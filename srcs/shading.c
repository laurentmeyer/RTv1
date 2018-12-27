#include "geometry.h"
#include "rtv1.h"
#include "raytracer.h"
#include "color.h"
#include <math.h>

t_color		normal_color(t_v3 *normal)
{
	return ((t_color){(normal->x + 1.) / 2., (normal->y + 1.) / 2., (normal->z + 1.) / 2.});
}

void		shade_pixel(t_ram *ram, t_hit *hit, t_ray *ray, t_color *out)
{
	double	diffuse;
	double	specular;
	t_light	*light;

	// ray = 0;
	// *color = normal_color(&(hit->normal));
	light = ram->scene->lights[0];
	diffuse = dot_product(light->direction, hit->normal);
	if (diffuse > 0.)
		*out = mul_v3(hit->object->material.color, light->intensity * diffuse * hit->object->material.diffuse);
	specular = dot_product(hit->normal, normalize(add_v3(inverse(ray->direction), light->direction)));
	if (specular <= 0.)
		specular = 0.;
	else
		specular = pow(specular, hit->object->material.phong_exponent) * hit->object->material.specular;
	*out = add_color(*out, mul_v3((t_color){1., 1., 1.}, light->intensity * specular));
}