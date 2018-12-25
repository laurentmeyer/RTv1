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
	t_object		*object;
	t_v4			normal;
}					t_hit;

#endif