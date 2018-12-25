#include "rtv1.h"
#include "raytracer.h"
#include "geometry.h"
#include <math.h>

void	hit_sphere(t_hit *out, t_ray *ray, t_object *sphere)
{
	t_v4	abc;
	double	t1;
	double	t2;
	double	divis;

	abc.x = dot_product_v4(ray->direction, ray->direction);
	abc.y = 2. * dot_product_v4(ray->direction, ray->origin);
	abc.z = dot_product_v4(ray->origin, ray->origin) - sphere->scale.x;
	abc.w = sqrt(abc.y * abc.y - 4 * abc.x * abc.z);
	divis = .5 / abc.x;
	t1 = (-abc.y + abc.w) * divis;
	t2 = (-abc.y - abc.w) * divis;
	if (t1 >= 0 && t2 < 0)
		out->distance = t1;
	else if (t2 >= 0 && t1 < 0)
		out->distance = t2;
	else
		out->distance = t1 < t2 ? t1 : t2;
}