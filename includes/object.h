#ifndef OBJECT_H
# define OBJECT_H

# include "geometry.h"
# define SPHERE    0
# define PLANE     1
# define CYLYNDER  2
# define CONE      3

typedef struct		s_object
{
	int				type;
	t_v3			position;
	t_v3			rotation;
	t_v3			scale;
	unsigned int	color;
}					t_object;

typedef struct		s_camera
{
	t_v3			position;
	t_v3			rotation;
	double			eye_distance;
	double			h_fov;
	t_v3			up_left;
	t_v3			down_right;
}					t_camera;

typedef struct		s_light
{
	t_v3			direction;
}					t_light;

t_object			*new_object(int type);
void				destroy_object(t_object *obj);
t_light				*new_light(t_v3 direction);
void				destroy_light(t_light *light);

#endif