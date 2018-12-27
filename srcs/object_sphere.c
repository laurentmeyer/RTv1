#include "rtv1.h"
#include "raytracer.h"
#include "geometry.h"
#include <math.h>

int			hit_sphere(t_hit *out, t_ray *ray, t_object *sphere)
{
	double	discriminant;
	t_v3	e_c;
	double	divis;
	double	t2;

	e_c = sub_v3(ray->origin, sphere->position);
	discriminant = dot_product(ray->direction, e_c);
	divis = dot_product(ray->direction, ray->direction);
	discriminant = discriminant * discriminant - divis *
		(dot_product(e_c, e_c) - sphere->scale.x * sphere->scale.x);
	if (discriminant < 0.)
		return (FALSE);
	discriminant = sqrt(discriminant);
	divis = 1 / divis;
	out->t = divis * (-dot_product(ray->direction, e_c) + discriminant);
	t2 = divis * (-dot_product(ray->direction, e_c) - discriminant);
	if (t2 > 0. && t2 < out->t)
		out->t = t2;
	return (out->t > 0.);
}

void				normal_sphere(t_hit *out)
{
	out->normal = mul_v3(sub_v3(out->point, out->object->position), 1. / out->object->scale.x);
	// out->normal = mul_v3(sub_v3(out->point, out->object->position), 2.);
}

// int			hit_sphere(t_hit *out, t_ray *ray, t_object *sphere)
// {
// 	t_v3 abc;
// 	double t1;
// 	double t2;
// 	double divis;

// 	abc.x = dot_product(ray->direction, ray->direction);
// 	abc.y = 2. * dot_product(ray->direction, ray->origin);
// 	abc.z = dot_product(ray->origin, ray->origin) - sphere->scale.x;
// 	t = sqrt(abc.y * abc.y - 4 * abc.x * abc.z);
// 	divis = .5 / abc.x;
// 	t1 = (-abc.y + t) * divis;
// 	t2 = (-abc.y - t) * divis;
// 	if (t1 >= 0 && t2 < 0)
// 		t = t1;
// 	else if (t2 >= 0 && t1 < 0)
// 		t = t2;
// 	else
// 		t = t1 < t2 ? t1 : t2;
// 	return (t > 0.);
// }