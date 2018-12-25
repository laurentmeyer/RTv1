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
	cam->up_left.z = cam->eye_distance;
	cam->up_left.w = 1.;
	// printf("upleft x=%f y=%f z=%f\n", cam->up_left.x, cam->up_left.y, cam->up_left.z);
	cam->down_right.x = - cam->up_left.x;
	cam->down_right.y = - cam->up_left.y;
	cam->down_right.z = - cam->up_left.z;
	cam->down_right.w = 1.;
}

void			init_scene(t_ram *ram)
{
	if (NULL == (ram->scene = (t_scene *)malloc(sizeof(t_scene))))
		exit_message(ram, ERROR, "Could not allocate display\n");
	ft_bzero(ram->scene, sizeof(t_scene));
	ram->scene->camera.eye_distance = .4;
	ram->scene->camera.h_fov = radians(40);
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
		destroy_object(scene->lights[i++]);
	free(scene);
}