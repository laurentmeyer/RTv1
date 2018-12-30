#include "rtv1.h"
#include "raytracer.h"
#include "geometry.h"
#include <math.h>

static inline void		get_coefficients(t_v3 *out, t_ray *ray, t_object *sphere)
{
	t_v3	x;

	*out = (t_v3){0., 0., 0.};
	out->x = dot_product(ray->direction, ray->direction);
	x = sub_v3(ray->origin, sphere->position);
	out->y = dot_product(x, ray->direction);
	out->y *= 2.;
	out->z += dot_product(x, x) - sphere->scale.x * sphere->scale.x;
}

int			hit_sphere(t_hit *out, t_ray *ray, t_object *sphere)
{
	t_v3	abc;
	double	t2;
	double	discriminant;
	double	divis;

	get_coefficients(&abc, ray, sphere);
	if ((discriminant = abc.y * abc.y - 4. * abc.x * abc.z) < 0.)
		return (FALSE);
	discriminant = sqrt(discriminant);
	divis = 1. / (2 * abc.x);
	out->t = (-abc.y + discriminant) * divis;
	if ((t2 = (-abc.y - discriminant) * divis) > 0. && t2 < out->t)
		out->t = t2;
	return (out->t > 0.);
}

void				normal_sphere(t_hit *out)
{
	out->normal = mul_v3(sub_v3(out->point, out->object->position), 1. / out->object->scale.x);
}