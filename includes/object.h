#ifndef OBJECT_H
# define OBJECT_H

# include "geometry.h"
# define CAMERA    0
# define LIGHT     1
# define SPHERE    2
# define PLANE     3
# define CYLYNDER  4
# define CONE      5

typedef struct		s_object
{
	int				type;
	t_v4			position;
	t_v4			rotation;
	t_v4			scale;
	unsigned int	color;
}					t_object;

typedef t_object	t_camera;
typedef t_object	t_light;

#endif