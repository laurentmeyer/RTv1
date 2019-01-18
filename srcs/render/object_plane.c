/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:09:38 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:09:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "raytracer.h"
#include "geometry.h"
#include <math.h>

int		hit_plane(t_hit *out, t_ray *ray, t_object *plane)
{
	t_v3	diff;

	out->normal = (t_v3){0., 1., 0.};
	out->normal = rotate_x(out->normal, plane->direction.x);
	out->normal = rotate_y(out->normal, plane->direction.y);
	out->normal = rotate_z(out->normal, plane->direction.z);
	diff = (t_v3){plane->position.x - ray->origin.x,
		plane->position.y - ray->origin.y, plane->position.z - ray->origin.z};
	out->t = dot_product(out->normal, ray->direction);
	if (out->t == 0.)
		return (FALSE);
	out->t = dot_product(out->normal, diff) / out->t;
	return (out->t > 0);
}

void	normal_plane(t_hit *out)
{
	(void)out;
	return ;
}
