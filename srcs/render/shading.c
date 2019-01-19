/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:09:47 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/19 12:08:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "rtv1.h"
#include "raytracer.h"
#include "color.h"
#include <math.h>

void		point_to_light(
				t_v3 *direction,
				double *intensity,
				t_light *light,
				t_v3 *point)
{
	t_v3	vec;

	*intensity = light->intensity;
	if (light->type == DIRECTIONAL)
		*direction = inverse(light->direction);
	else if (light->type == SPOT)
	{
		vec = sub_v3(light->position, *point);
		*direction = normalize(vec);
		*intensity = *intensity / pow(magnitude(vec), 0.4);
	}
}

t_color		shade_one_light(t_ram *ram, t_hit *hit, t_ray *ray, t_light *light)
{
	t_color	color;
	double	diffuse;
	double	specular;
	t_ray	l;
	double	intensity;

	point_to_light(&(l.direction), &intensity, light, &(hit->point));
	l.origin = hit->point;
	l.max_length = magnitude(sub_v3(hit->point, light->position));
	color = (t_color){0., 0., 0.};
	if (closest_intersection(ram->scene, &l, NULL))
		return (color);
	diffuse = dot_product(l.direction, hit->normal);
	if (diffuse > 0.)
		color = mul_v3(hit->object->material.color,
					intensity * diffuse * hit->object->material.diffuse);
	specular = dot_product(hit->normal,
					normalize(add_v3(inverse(ray->direction), l.direction)));
	if (specular <= 0.)
		return (color);
	else
		specular = pow(specular, hit->object->material.phong_exponent) *
			hit->object->material.specular;
	return (add_color(color,
					mul_v3((t_color){1., 1., 1.}, intensity * specular)));
}

void		shade_pixel(t_ram *ram, t_hit *hit, t_ray *ray, t_color *out)
{
	size_t i;

	*out = (t_v3){0., 0., 0.};
	i = 0;
	while (i < ram->scene->lights_count)
		*out = add_color(*out,
				shade_one_light(ram, hit, ray, ram->scene->lights[i++]));
}
