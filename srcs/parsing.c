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

int parse_line(t_ram *ram, char *start)
{
	static int curr_type = -1;

	if (NULL != ram->parsing.split)
	{
		ft_free_strsplit(&(ram->parsing.split));
		ram->parsing.split = NULL;
	}
	if (NULL != start)
	{
		ram->parsing.split = ft_strsplit(start, '\t');
		if (0 == ft_strcmp(ram->parsing.split[0], "object"))
			curr_type = I_OBJECT;
		else if (0 == ft_strcmp(ram->parsing.split[0], "camera"))
			curr_type = I_CAMERA;
		else if (0 == ft_strcmp(ram->parsing.split[0], "light"))
			curr_type = I_LIGHT;
	}
	if (I_OBJECT == curr_type)
		return (parse_object(ram));
	else if (I_LIGHT == curr_type)
		return (parse_light(ram));
	else if (I_CAMERA == curr_type)
		return (parse_camera(ram));
	return (ERROR);
}

char *format_line(char *str)
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

void parse_file(t_ram *ram)
{
	int g;
	char *start;

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
			break;
		start = format_line(ram->parsing.line);
		if (*start != '#' && *start != '\0' && ERROR == parse_line(ram, start))
		{
			ft_putstr_fd("Parsing error near: ", 2);
			ft_putstr_fd(start, 2);
			break ;
		}
	}
	parse_line(ram, NULL);
}