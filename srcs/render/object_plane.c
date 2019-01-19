/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:09:38 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/19 12:05:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "raytracer.h"
#include "geometry.h"
#include <math.h>

int		hit_plane(t_hit *out, t_ray *ray, t_object *plane)
{
	double	denom;

	out->normal = (t_v3){0., 1., 0.};
	out->normal = rotate_x(out->normal, plane->direction.x);
	out->normal = rotate_y(out->normal, plane->direction.y);
	out->normal = rotate_z(out->normal, plane->direction.z);
	denom = dot_product(out->normal, ray->direction);
	if (fabs(denom) < 0.0001)
		return (FALSE);
	out->t = dot_product(out->normal,
		sub_v3(plane->position, ray->origin)) / denom;
	return (out->t > 0.0001);
}

void	normal_plane(t_hit *out)
{
	(void)out;
	return ;
}
