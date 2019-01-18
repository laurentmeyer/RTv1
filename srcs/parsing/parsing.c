/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:07:25 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 13:01:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "get_next_line.h"
#include "rtv1.h"

size_t		count_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static void	prepare_parse_line(
				t_ram *ram,
				t_parse_f *funs,
				char *start,
				int curr_index)
{
	if (NULL != ram->parsing.split)
	{
		ft_free_strsplit(&(ram->parsing.split));
		ram->parsing.split = NULL;
	}
	if (NULL == start && -1 != curr_index)
	{
		ram->parsing.flush = TRUE;
		(funs[curr_index])(ram);
	}
}

int			parse_line(t_ram *ram, char *start)
{
	static char			*dict[] = {"object", "camera", "light", NULL};
	static t_parse_f	funs[] = {&parse_object, &parse_camera,
									parse_light, NULL};
	static int			curr_index = -1;
	int					index;

	prepare_parse_line(ram, funs, start, curr_index);
	if (NULL != start && (ram->parsing.split = ft_strsplit(start, '\t'))
		&& (-1 != (index = ft_index((char **)dict, ram->parsing.split[0]))))
	{
		if (-1 != curr_index)
		{
			ram->parsing.flush = TRUE;
			(funs[curr_index])(ram);
		}
		curr_index = index;
	}
	if (-1 != curr_index)
		return ((*(funs[curr_index]))(ram));
	return (SUCCESS);
}

char		*format_line(char *str)
{
	char *line;

	line = str;
	while (*line != '\0')
	{
		if (*line == ' ')
			*line = '\t';
		line++;
	}
	line = str;
	while (*line == '\t')
		line++;
	return (line);
}

void		t_parse_file(t_ram *ram)
{
	int		g;
	char	*start;

	while (42)
	{
		if (NULL != ram->parsing.line)
		{
			free(ram->parsing.line);
			ram->parsing.line = NULL;
		}
		g = gnlite(ram->parsing.fd, &(ram->parsing.line));
		if (g < 0)
			exit_message(ram, -1, "Parsing error\n");
		if (0 == g)
			break ;
		start = format_line(ram->parsing.line);
		if (*start != '#' && *start != '\0' && ERROR == parse_line(ram, start))
		{
			ft_putstr_fd("Parsing error near: \"", 2);
			ft_putstr_fd(ram->parsing.line, 2);
			exit_message(ram, ERROR, "\"\n");
		}
	}
	parse_line(ram, NULL);
}
