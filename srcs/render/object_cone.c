/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:08:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:20:36 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "raytracer.h"
#include "geometry.h"
#include <math.h>

/*
** http://hugi.scene.org/online/hugi24/
**		coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm
*/

static inline void		get_coefficients(t_v3 *out, t_ray *ray, t_object *cone)
{
	double	tmp;
	t_v3	x;
	double	k;

	k = cone->scale.y / cone->scale.x * 0.5;
	k = 1. + k * k;
	*out = (t_v3){dot_product(ray->direction, ray->direction), 0., 0.};
	tmp = dot_product(ray->direction, cone->direction);
	out->x -= tmp * tmp * k;
	out->y -= tmp * k;
	x = sub_v3(ray->origin, cone->position);
	tmp = dot_product(x, cone->direction);
	out->y *= tmp;
	out->y += dot_product(ray->direction, x);
	out->y *= 2.;
	out->z -= tmp * tmp * k;
	out->z += dot_product(x, x);
}

int						hit_cone(t_hit *out, t_ray *ray, t_object *cone)
{
	t_v3	abc;
	double	t2;
	double	discriminant;
	double	divis;

	get_coefficients(&abc, ray, cone);
	if ((discriminant = abc.y * abc.y - 4. * abc.x * abc.z) < 0.)
		return (FALSE);
	discriminant = sqrt(discriminant);
	divis = 1. / (2 * abc.x);
	out->t = (-abc.y + discriminant) * divis;
	if ((t2 = (-abc.y - discriminant) * divis) > 0. && t2 < out->t)
		out->t = t2;
	return (out->t > 0.);
}

void					normal_cone(t_hit *out)
{
	double		m;
	double		k;

	k = (out->object->scale.y / out->object->scale.x) * .5;
	k = 1. + k * k;
	m = dot_product(out->ray.direction, out->object->direction) * out->t;
	m += dot_product(
			sub_v3(out->ray.origin, out->object->position),
			out->object->direction);
	out->normal = sub_v3(out->point, out->object->position);
	out->normal = sub_v3(out->normal, mul_v3(out->object->direction, m * k));
	out->normal = normalize(out->normal);
}
