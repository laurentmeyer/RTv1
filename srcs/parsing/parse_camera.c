/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:07:13 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/19 15:07:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "get_next_line.h"
#include "rtv1.h"
#include "object.h"

int		parse_args(t_ram *ram)
{
	t_camera	*camera;
	char		**args;
	size_t		c;
	t_v3		vec;

	args = ram->parsing.split;
	camera = &(ram->scene->camera);
	if ((c = count_args(args)) == 4)
	{
		vec = (t_v3){ft_atof(args[1]), ft_atof(args[2]), ft_atof(args[3])};
		if (0 == ft_strcmp(args[0], "position"))
			camera->position = vec;
		else if (0 == ft_strcmp(args[0], "rotation"))
			camera->rotation = vec;
		else
			return (ERROR);
	}
	else
		return (ERROR);
	return (SUCCESS);
}

int		parse_camera(t_ram *ram)
{
	char			**args;

	args = ram->parsing.split;
	if (NULL == args || ram->parsing.flush
		|| (1 == count_args(args) && 0 == ft_strcmp(args[0], "camera")))
		ram->parsing.flush = FALSE;
	else
		return (parse_args(ram));
	return (SUCCESS);
}
