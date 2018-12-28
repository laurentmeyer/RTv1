#include "scene.h"
#include "rtv1.h"
#include "ft_math.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h> //

static void		update_camera(t_camera *cam)
{
	cam->up_left.x = cam->eye_distance * tan(-cam->h_fov / 2);
	cam->up_left.y = - cam->up_left.x * WIN_H / WIN_W;
	cam->up_left.z =  - cam->eye_distance;
	cam->pixel_steps.x = -2. * cam->up_left.x / WIN_W;
	cam->pixel_steps.y = -2. * cam->up_left.y / WIN_H;
}

void			init_scene(t_ram *ram)
{
	if (NULL == (ram->scene = (t_scene *)malloc(sizeof(t_scene))))
		exit_message(ram, ERROR, "Could not allocate display\n");
	ft_bzero(ram->scene, sizeof(t_scene));
	ram->scene->camera.eye_distance = .4;
	ram->scene->camera.h_fov = radians(40);
	ram->scene->ambiant_light = 0.15;
	update_camera(&ram->scene->camera);
}

void 			free_scene(t_scene *scene)
{
	size_t	i;

	i = 0;
	while (i < scene->objects_count)
		destroy_object(scene->objects[i++]);
	i = 0;
	while (i < scene->lights_count)
		destroy_light(scene->lights[i++]);
	free(scene);
}