#ifndef SCENE_H
# define SCENE_H

# include "object.h"
# include <stdlib.h>
# define MAX_OBJECTS 12
# define MAX_LIGHTS 2

typedef struct		s_scene
{
	t_camera		camera;
	t_object		*objects[MAX_OBJECTS];
	size_t			objects_count;
	t_light			*lights[MAX_LIGHTS];
	size_t			lights_count;
	double			ambiant_light;
}					t_scene;

#endif