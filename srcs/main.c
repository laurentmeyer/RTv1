#include "rtv1.h"
#include "object.h"
#include "scene.h"
#include "ft_math.h"

void		populate_scene(t_scene *scene)
{
	t_object	*object;

	scene->camera.position = (t_v4){1., 2., -10., 1.};

	object = new_object(PLANE);
	object->color = 0xFF;
	object->rotation = (t_v4){0., 0., radians(15.), 1.};
	scene->objects[(scene->objects_count++)] = object;

	object = new_object(SPHERE);
	object->color = 0xff0000;
	object->scale = (t_v4){.5, .5, .5, 1.};
	scene->objects[(scene->objects_count++)] = object;

	object = new_object(SPHERE);
	object->color = 0x00FF00;
	object->position = (t_v4){0., 0., .3, 1.};
	object->scale = (t_v4){.5, .5, .5, 1.};
	scene->objects[(scene->objects_count++)] = object;

	object = new_object(SPHERE);
	object->color = 0xFF00FF;
	object->position = (t_v4){.4, 0., .1, 1.};
	object->scale = (t_v4){.3, .3, .3, 1.};
	scene->objects[(scene->objects_count++)] = object;
}

int			main(void)
{
	t_ram	*ram;

	ram = init_ram();
	populate_scene(ram->scene);
	render_scene(ram);
	mlx_loop(ram->display->mlx_ptr);
	return (0);
}
