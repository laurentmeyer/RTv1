/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:07:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/19 15:07:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "get_next_line.h"
#include "rtv1.h"
#include "object.h"

static t_light	*push_light(t_ram *ram, t_light *light)
{
	if (NULL != light)
		ram->scene->lights[(ram->scene->lights_count++)] = light;
	if (MAX_LIGHTS == ram->scene->lights_count)
		ft_putendl_fd("Maximum number of lights reached", 2);
	return (NULL);
}

static int		parse_args(char **args, t_light *light)
{
	size_t	c;
	t_v3	vec;
	double	d;

	if ((c = count_args(args)) == 4)
	{
		vec = (t_v3){ft_atof(args[1]), ft_atof(args[2]), ft_atof(args[3])};
		if (0 == ft_strcmp(args[0], "position"))
			light->position = vec;
		else if (0 == ft_strcmp(args[0], "direction"))
			light->direction = normalize(vec);
		else
			return (ERROR);
	}
	else if (c == 2)
	{
		d = ft_atof(args[1]);
		if (0 == ft_strcmp(args[0], "intensity"))
			light->intensity = ft_bound(0., 1., d);
		else
			return (ERROR);
	}
	else
		return (ERROR);
	return (SUCCESS);
}

int				parse_light(t_ram *ram)
{
	static t_light	*light = NULL;
	char			**args;

	args = ram->parsing.split;
	if (MAX_LIGHTS == ram->scene->lights_count)
		return (SUCCESS);
	if (NULL == args || ram->parsing.flush)
	{
		light = push_light(ram, light);
		ram->parsing.flush = FALSE;
	}
	else if (2 == count_args(args) && 0 == ft_strcmp(args[0], "light"))
	{
		push_light(ram, light);
		if (0 == ft_strcmp(args[1], "directional"))
			light = new_light(DIRECTIONAL);
		else if (0 == ft_strcmp(args[1], "spot"))
			light = new_light(SPOT);
	}
	else
		return (parse_args(args, light));
	return (SUCCESS);
}
