#include "geometry.h"
#include "rtv1.h"
#include "raytracer.h"
#include "color.h"
#include <math.h>

t_color		normal_color(t_v3 *normal)
{
	return ((t_color){(normal->x + 1.) / 2., (normal->y + 1.) / 2., (normal->z + 1.) / 2.});
}

void		point_to_light(t_v3 *direction, double *intensity, t_light *light, t_v3 *point)
{
	t_v3	vec;

	*intensity = light->intensity;
	if (light->type == DIRECTIONAL)
		*direction = light->direction;
	else if (light->type == SPOT)
	{
		vec = sub_v3(light->position, *point);
		*direction = normalize(vec);
		*intensity = *intensity / pow(magnitude(vec), 0.4); //
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
	color = (t_color){0., 0., 0.};
	if (intersection(ram->scene, &l, 0.00001))
		return (color);
	diffuse = dot_product(l.direction, hit->normal);
	if (diffuse > 0.)
		color = mul_v3(hit->object->material.color, intensity * diffuse * hit->object->material.diffuse);
	specular = dot_product(hit->normal, normalize(add_v3(inverse(ray->direction), l.direction)));
	if (specular <= 0.)
		specular = 0.;
	else
		specular = pow(specular, hit->object->material.phong_exponent) * hit->object->material.specular;
	return (add_color(color, mul_v3((t_color){1., 1., 1.}, intensity * specular)));
}

void shade_pixel(t_ram *ram, t_hit *hit, t_ray *ray, t_color *out)
{
	size_t i;

	// *out = mul_v3(hit->object->material.color, ram->scene->ambiant_light);
	*out = mul_v3(hit->object->material.color, 0.);
	i = 0;
	while (i < ram->scene->lights_count)
		*out = add_color(*out, shade_one_light(ram, hit, ray, ram->scene->lights[i++]));
}