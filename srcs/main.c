#include "rtv1.h"
#include "object.h"
#include "scene.h"

void		populate_scene(t_scene *scene)
{
	t_object	*object;

	object = new_object(SPHERE);
	object->color = 0xff0000;
	object->position.y = 1.;
	object->position.z = 5.;
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
