#include "rtv1.h"
#include "raytracer.h"
#include "geometry.h"
#include <math.h>

static void	fill_point_and_normal(t_hit *hit, t_ray *ray, double t)
{
		hit->point = (t_v3){ ray->origin.x + t * ray->direction.x,
			ray->origin.y + t * ray->direction.y,
		   ray->origin.z + t * ray->direction.z };
		hit->normal = normalize(hit->point);
}

double hit_sphere(t_hit *out, t_ray *ray, t_object *sphere)
{
	t_v3 abc;
	double t;
	double t1;
	double t2;
	double divis;

	out->object = sphere;
	abc.x = dot_product(ray->direction, ray->direction);
	abc.y = 2. * dot_product(ray->direction, ray->origin);
	abc.z = dot_product(ray->origin, ray->origin) - sphere->scale.x;
	t = sqrt(abc.y * abc.y - 4 * abc.x * abc.z);
	divis = .5 / abc.x;
	t1 = (-abc.y + t) * divis;
	t2 = (-abc.y - t) * divis;
	if (t1 >= 0 && t2 < 0)
		t = t1;
	else if (t2 >= 0 && t1 < 0)
		t = t2;
	else
		t = t1 < t2 ? t1 : t2;
	if (t > 0.)
		fill_point_and_normal(out, ray, t);
	return (t);
}