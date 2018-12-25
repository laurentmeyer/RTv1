#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "geometry.h"
# include "object.h"

typedef struct		s_ray
{
	t_v4			origin;
	t_v4			direction;
}					t_ray;

typedef struct		s_hit
{
	double			distance;
	// t_v4			normal;
}					t_hit;

void				get_collision(t_hit *out, t_ray *ray, t_object *object);
void				hit_sphere(t_hit *out, t_ray *ray, t_object *sphere);

#endif