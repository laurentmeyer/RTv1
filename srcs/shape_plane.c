#include "rtv1.h"
#include "raytracer.h"
#include "geometry.h"
#include <math.h>

double hit_plane(t_hit *out, t_ray *ray, t_object *plane)
{
	double t;
	t_v3 diff;

	out->object = plane;
	out->normal = (t_v3){0., 1., 0.};
	diff = (t_v3){plane->position.x - ray->origin.x,
		plane->position.y - ray->origin.y, plane->position.z - ray->origin.z};
	t = dot_product(out->normal, ray->direction);
	if (t == 0.)
		return (-1.);
	t = dot_product(out->normal, diff) / t;
	out->point = (t_v3){ray->origin.x + t * ray->direction.x,
						ray->origin.y + t * ray->direction.y,
						ray->origin.z + t * ray->direction.z};
	// out->distance = magnitude((t_v3){ out->point.x + t * ray->origin.x,
	// 					out->point.y + t * ray->origin.y,
	// 					out->point.z + t * ray->origin.z });
	return (t);
}