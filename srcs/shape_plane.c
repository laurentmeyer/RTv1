#include "rtv1.h"
#include "raytracer.h"
#include "geometry.h"
#include <math.h>

void	hit_plane(t_hit *out, t_ray *ray, t_object *plane)
{
	double	t;
	t_v4	normal;
	t_v4	diff;

	normal = (t_v4){0., 1., 0., 1.};
	diff = (t_v4){plane->position.x - ray->origin.x, plane->position.y -
		ray->origin.y, plane->position.z - ray->origin.z, 1.};
	t = dot_product_v4(normal, ray->direction);
	if (t == 0.)
		out->distance = -1.;
	else
		out->distance = dot_product_v4(normal, diff) / t;
}