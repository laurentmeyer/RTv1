#include "geometry.h"
#include "rtv1.h"
#include "raytracer.h"
#include "object.h"
#include <float.h>

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

int			intersection(t_scene *scene, t_ray * const ray, double epsilon)
{
	size_t			i;
	t_hit			tmp;
	
	i = 0;
	while (i < scene->objects_count)
	{
		if (hit_object(&tmp, *ray, scene->objects[i]) && tmp.t > epsilon)
			return (TRUE);
		++i;
	}
	return (FALSE);
}

int			closest_intersection(t_scene *scene, t_ray * const ray, t_hit *dst)
{
	size_t			i;
	double			min_dist;
	t_hit			tmp;
	int				found;
	
	min_dist = DBL_MAX;
	i = 0;
	found = FALSE;
	while (i < scene->objects_count)
	{
		if (hit_object(&tmp, *ray, scene->objects[i]) && tmp.t < min_dist)
		{
			min_dist = tmp.t;
			*dst = tmp;
			dst->object = scene->objects[i];
			found = TRUE;
		}
		++i;
	}
	return (found);
}