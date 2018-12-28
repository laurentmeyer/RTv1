#ifndef PARSING_H
# define PARSING_H

# include "geometry.h"
# include "scene.h"
# define I_LIGHT  0
# define I_OBJECT 1
# define I_CAMERA 2

typedef struct		s_i_object
{
	int				type;
	t_v3			position;
	t_v3			rotation;
	t_v3			scale;
	t_material		material;
}					t_i_object;

typedef struct		s_i_light
{
	int				type;
	t_v3			direction;
	t_v3			position;
	double			intensity;
}					t_i_light;

typedef struct		s_parsing
{
	int				fd;
	char			*line;
	char			**split;
	int				win_h;
	int				win_w;
	t_v3			camera_position;
	t_v3			camera_rotation;
	double			focal_length;
	double			horizontal_fov;
	t_i_object		objects[MAX_OBJECTS];
	size_t			objects_count;
	t_i_light		lights[MAX_LIGHTS];
	size_t			lights_count;
	double			ambiant_light;

}					t_parsing;

size_t				count_args(char **args);

#endif