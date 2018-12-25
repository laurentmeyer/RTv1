#include "scene.h"
#include "rtv1.h"
#include <stdlib.h>

void	init_scene(t_ram *ram)
{
	if (NULL == (ram->scene = (t_scene *)malloc(sizeof(t_scene))))
		exit_message(ram, ERROR, "Could not allocate display\n");
	ft_bzero(ram->scene, sizeof(t_scene));
	ram->scene->camera = new_object(CAMERA);
}

void free_scene(t_scene *scene)
{
	size_t	i;

	i = 0;
	while (i < scene->objects_count)
		destroy_object(scene->objects[i++]);
	i = 0;
	while (i < scene->lights_count)
		destroy_object(scene->lights[i++]);
	destroy_object(scene->camera);
	free(scene);
}