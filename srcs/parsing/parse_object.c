#include "parsing.h"
#include "libft.h"
#include "get_next_line.h"
#include "rtv1.h"
#include "ft_math.h"
#include "geometry.h"
#include "object.h"
#include <stdio.h>

static t_object *push_object(t_ram *ram, t_object *object)
{
	if (NULL != object)
		ram->scene->objects[(ram->scene->objects_count++)] = object;
 	if (MAX_OBJECTS == ram->scene->objects_count)
		ft_putendl_fd("Maximum number of objects reached", 2);
	return (NULL);
}

static int		parse_args(char **args, t_object *object)
{
	size_t	c;
	t_v3	vec;

	if ((c = count_args(args)) == 4)
	{
		vec = (t_v3){ft_atof(args[1]), ft_atof(args[2]), ft_atof(args[3])};
		// printf("x=%.2f y=%.2f z=%.2f\n", vec.x, vec.y, vec.z);
		if (0 == strcmp(args[0], "position"))
			object->position = vec;
		else if (0 == strcmp(args[0], "scale"))
			object->scale = vec;
		else if (0 == strcmp(args[0], "rotation"))
		{
			object->direction = (t_v3){0., 1., 0.};
			object->direction = rotate_x(object->direction, radians(vec.x));
			object->direction = rotate_y(object->direction, radians(vec.y));
			object->direction = rotate_z(object->direction, radians(vec.z));
		}
		else if (0 == strcmp(args[0], "color"))
			object->material.color = vec;
		else
			return (ERROR);
	}
	else if (c == 2)
	{
		if (0 == strcmp(args[0], "diffuse"))
			object->material.diffuse = ft_atof(args[1]);
		else if (0 == strcmp(args[0], "specular"))
			object->material.specular = ft_atof(args[1]);
		else if (0 == strcmp(args[0], "phong"))
			object->material.phong_exponent = ft_atof(args[1]);
		else
			return (ERROR);
	}
	else
		return (ERROR);
	return (SUCCESS);
}

int parse_object(t_ram *ram)
{
	static t_object *object = NULL;
	char **args;

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
		// if (0 == ft_strcmp(args[1], "sphere"))
		// 	object = new_object(SPHERE);
		// else if (0 == ft_strcmp(args[1], "plane"))
		// 	object = new_object(PLANE);
		// else if (0 == ft_strcmp(args[1], "cylinder"))
		// 	object = new_object(CYLINDER);
	}
	else
		return (parse_args(args, object));
	return (SUCCESS);
}