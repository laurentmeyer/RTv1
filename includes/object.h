#ifndef OBJECT_H
# define OBJECT_H

# include "geometry.h"
# define LIGHT     0
# define SPHERE    1
# define PLANE     2
# define CYLYNDER  3
# define CONE      4

typedef struct		s_object
{
	int				type;
	t_v4			position;
	t_v4			rotation;
	t_v4			scale;
	unsigned int	color;
}					t_object;

typedef struct		s_camera
{
	t_v4			position;
	t_v4			rotation;
	double			eye_distance;
	double			h_fov;
	t_v4			up_left;
	t_v4			down_right;
}					t_camera;

typedef t_object	t_light;

#endif