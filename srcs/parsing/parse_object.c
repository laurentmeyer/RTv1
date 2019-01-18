/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:07:22 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:54:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "get_next_line.h"
#include "rtv1.h"
#include "ft_math.h"
#include "geometry.h"
#include "object.h"
#include <stdio.h>

static t_object		*push_object(t_ram *ram, t_object *object)
{
	if (NULL != object)
		ram->scene->objects[(ram->scene->objects_count++)] = object;
	if (MAX_OBJECTS == ram->scene->objects_count)
		ft_putendl_fd("Maximum number of objects reached", 2);
	return (NULL);
}

static int			parse4_args(char *args0, t_object *object, t_v3 vec)
{
	if (0 == strcmp(args0, "position"))
		object->position = vec;
	else if (0 == strcmp(args0, "scale"))
		object->scale = vec;
	else if (0 == strcmp(args0, "color"))
		object->material.color = vec;
	else if (0 == strcmp(args0, "rotation"))
	{
		object->direction = (t_v3){0., 1., 0.};
		object->direction = rotate_x(object->direction, radians(vec.x));
		object->direction = rotate_y(object->direction, radians(vec.y));
		object->direction = rotate_z(object->direction, radians(vec.z));
	}
	else
		return (0);
	return (1);
}

static int			parse2_args(char *args0, t_object *object, double d)
{
	if (0 == strcmp(args0, "diffuse"))
		object->material.diffuse = d;
	else if (0 == strcmp(args0, "specular"))
		object->material.specular = d;
	else if (0 == strcmp(args0, "phong"))
		object->material.phong_exponent = d;
	else
		return (0);
	return (1);
}

static int			parse_args(char **args, t_object *object)
{
	size_t	c;
	t_v3	vec;

	if ((c = count_args(args)) == 4)
	{
		vec = (t_v3){ft_atof(args[1]), ft_atof(args[2]), ft_atof(args[3])};
		if (parse4_args(args[0], object, vec) == 0)
			return (ERROR);
	}
	else if (c == 2)
	{
		if (parse2_args(args[0], object, ft_atof(args[1])) == 0)
			return (ERROR);
	}
	else
		return (ERROR);
	return (SUCCESS);
}

int					parse_object(t_ram *ram)
{
	static t_object		*object = NULL;
	char				**args;

	args = ram->parsing.split;
	if (MAX_OBJECTS == ram->scene->objects_count)
		return (SUCCESS);
	if (NULL == args || ram->parsing.flush)
	{
		object = push_object(ram, object);
		ram->parsing.flush = FALSE;
	}
	else if (2 == count_args(args) && 0 == ft_strcmp(args[0], "object"))
	{
		push_object(ram, object);
		if (NULL == (object = new_object(args[1])))
		{
			ft_putstr_fd("Unable to create object: ", 2);
			exit_message(ram, ERROR, args[1]);
		}
	}
	else
		return (parse_args(args, object));
	return (SUCCESS);
}
