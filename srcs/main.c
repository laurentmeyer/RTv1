#include "rtv1.h"
#include "object.h"
#include "scene.h"
#include "ft_math.h"

void		populate_scene(t_scene *scene)
{
	t_object	*object;

	// scene->camera.position = (t_v3){1., 2., -10.};
	// scene->camera.position = (t_v3){0., 0., 5.};
	scene->camera.position = (t_v3){0., 0.2, 5.};
	// scene->camera.rotation = (t_v3){0., radians(180.), .0};

	t_light		*light;
	light = new_light((t_v3){1., 1., 3. }, 1.);
	scene->lights[(scene->lights_count)++] = light;

	// object = new_object(PLANE);
	// object->position = (t_v3){0., -.2, 0. };
	// object->material.color = (t_color){1., 0., 0.};
	// object->material.diffuse = 1.;
	// object->material.specular = 0.2;
	// object->material.phong_exponent = 100.;
	// // object->rotation = (t_v3){0., 0., radians(-15.) };
	// scene->objects[(scene->objects_count++)] = object;

	object = new_object(SPHERE);
	object->material.color = (t_color){1., 0.5, 0.};
	// object->position = (t_v3){0., .2, 0. };
	object->material.diffuse = 0.8;
	object->material.specular = 0.8;
	object->material.phong_exponent = 300.;
	object->scale = (t_v3){.5, .5, .5 };
	scene->objects[(scene->objects_count++)] = object;

	object = new_object(SPHERE);
	object->material.color = (t_color){0., 0.8, 0.3};
	object->position = (t_v3){-1., -.5, -2. };
	object->material.diffuse = 0.8;
	object->material.specular = 0.5;
	object->material.phong_exponent = 100.;
	object->scale = (t_v3){.3, .3, .3 };
	scene->objects[(scene->objects_count++)] = object;

	object = new_object(SPHERE);
	object->material.color = (t_color){1., 0.5, 0.5};
	object->position = (t_v3){.7, -.4, 2. };
	object->material.diffuse = 0.9;
	object->material.specular = 0.6;
	object->material.phong_exponent = 200.;
	object->scale = (t_v3){.3, .3, .3 };
	scene->objects[(scene->objects_count++)] = object;

	// object = new_object(SPHERE);
	// object->material.color = 0x00FF00;
	// object->position = (t_v3){2., 0., .3 };
	// object->scale = (t_v3){.5, .5, .5 };
	// scene->objects[(scene->objects_count++)] = object;

	// object = new_object(SPHERE);
	// object->material.color = 0x7FFF;
	// object->position = (t_v3){-1., 2., .1 };
	// object->scale = (t_v3){.3, .3, .3 };
	// scene->objects[(scene->objects_count++)] = object;
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
