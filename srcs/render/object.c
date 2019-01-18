/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:09:42 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:16:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "rtv1.h"
#include "geometry.h"
#include <stdlib.h>

t_object	*new_object(char *type)
{
	static char		*dict[] = {"sphere", "plane", "cylinder", "cone", NULL};
	static t_hit_f	hit[] = {&hit_sphere, &hit_plane, &hit_cylinder,
								&hit_cone, NULL};
	static t_norm_f	norm[] = {&normal_sphere, &normal_plane, &normal_cylinder,
								&normal_cylinder, NULL};
	int				index;
	t_object		*obj;

	if (-1 == (index = ft_index(dict, type))
		|| NULL == (obj = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	ft_bzero(obj, sizeof(t_object));
	obj->hit_f = hit[index];
	obj->norm_f = norm[index];
	obj->direction = (t_v3){0., 1., 0.};
	obj->scale = (t_v3){1., 1., 1.};
	obj->material.color = (t_color){1., 1., 1.};
	obj->material.diffuse = 1.;
	return (obj);
}

t_light		*new_light(int type)
{
	t_light *light;

	if ((light = (t_light *)malloc(sizeof(t_light))) != NULL)
	{
		ft_bzero(light, sizeof(t_light));
		light->type = type;
		light->intensity = 1.;
	}
	return (light);
}

void		destroy_light(t_light *light)
{
	free(light);
}

void		destroy_object(t_object *obj)
{
	free(obj);
}
