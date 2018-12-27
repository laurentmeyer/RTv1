#include "geometry.h"
#include "rtv1.h"
#include "raytracer.h"
#include "object.h"

void		get_normal(t_hit *out, t_ray *ray)
{
	out->point = add_v3(ray->origin, mul_v3(ray->direction, out->t));
	if (out->object->type == SPHERE)
		normal_sphere(out);
}

int		hit_object(t_hit *out, t_ray ray, t_object *object)
{
	if (object->type == SPHERE)
		return (hit_sphere(out, &ray, object));
	if (object->type == PLANE)
		return (hit_plane(out, &ray, object));
	return (0);
}