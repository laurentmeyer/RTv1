#ifndef OBJECT_H
# define OBJECT_H

# include "geometry.h"
# include "color.h"
# define SPHERE    0
# define PLANE     1
# define CYLYNDER  2
# define CONE      3

typedef	struct		s_material
{
	t_color			color;
	double			phong_exponent;
	double			diffuse;
	double			specular;
}					t_material;

typedef struct		s_object
{
	int				type;
	t_v3			position;
	t_v3			rotation;
	t_v3			scale;
	t_material		material;
}					t_object;

typedef struct		s_camera
{
	t_v3			position;
	t_v3			rotation;
	double			eye_distance;
	double			h_fov;
	t_v3			up_left;
	t_v3			pixel_steps;
}					t_camera;

typedef struct		s_light
{
	t_v3			direction;
	double			intensity;
}					t_light;

t_object			*new_object(int type);
void				destroy_object(t_object *obj);
t_light				*new_light(t_v3 direction, double intensity);
void				destroy_light(t_light *light);

#endif