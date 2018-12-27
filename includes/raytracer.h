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
	double			t;
	t_v3			point;
	t_v3			normal;
	t_object		*object;
}					t_hit;

int					hit_object(t_hit *out, t_ray ray, t_object *object);
int					hit_sphere(t_hit *out, t_ray *ray, t_object *sphere);
int					hit_plane(t_hit *out, t_ray *ray, t_object *plane);
void				get_normal(t_hit *out, t_ray *ray);
void				normal_sphere(t_hit *out);

#endif