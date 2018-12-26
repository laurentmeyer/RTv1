#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "geometry.h"
# include "object.h"

typedef struct		s_ray
{
	t_v3			origin;
	t_v3			direction;
}					t_ray;

typedef struct		s_hit
{
	t_v3			point;
	t_v3			normal;
	t_object		*object;
}					t_hit;

double				get_collision(t_hit *out, t_ray ray, t_object *object);
double				hit_sphere(t_hit *out, t_ray *ray, t_object *sphere);
double				hit_plane(t_hit *out, t_ray *ray, t_object *plane);

#endif