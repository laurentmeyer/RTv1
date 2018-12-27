#include "rtv1.h"
#include "raytracer.h"
#include "ft_math.h"
#include "color.h"
#include <float.h>

void			screen_to_world(t_ram *ram, t_ray *ray, int x, int y)
{
	if (x == WIN_W / 2 && y == WIN_H / 2)
		x = WIN_W / 2;
	ray->origin = ram->scene->camera.position;
	ray->direction.x = ram->scene->camera.up_left.x + x * ram->scene->camera.pixel_steps.x;
	ray->direction.y = ram->scene->camera.up_left.y + y * ram->scene->camera.pixel_steps.y;
	ray->direction.z = ram->scene->camera.up_left.z;
	ray->direction = normalize(ray->direction); // optimiser, je pense que ce calcul peut être évité
}

int			closest_intersection(t_scene *scene, t_ray * const ray, t_hit *dst)
{
	size_t			i;
	double			min_dist;
	t_hit			tmp;
	int				found;
	
	min_dist = DBL_MAX;
	i = 0;
	found = FALSE;
	while (i < scene->objects_count)
	{
		if (hit_object(&tmp, *ray, scene->objects[i]) && tmp.t < min_dist)
		{
			min_dist = tmp.t;
			*dst = tmp;
			dst->object = scene->objects[i];
			found = TRUE;
		}
		++i;
	}
	return (found);
}

void render_pixel(unsigned int *out, t_ram *ram, int x, int y)
{
	t_ray ray;
	t_hit hit;
	t_color color;

	screen_to_world(ram, &ray, x, y);
	color = (t_color){0., 0., 0.};
	if (closest_intersection(ram->scene, &ray, &hit))
	{
		get_normal(&hit, &ray);
		shade_pixel(ram, &hit, &ray, &color);
	}
	int_of_color(out, &color);
}

int render_scene(t_ram *ram)
{
	t_image *img;
	unsigned int color;

	img = ram->display->mlx_img;
	for (int i = 0; i < WIN_W; i++)
		for (int j = 0; j < WIN_H; j++)
		{
			render_pixel(&color, ram, i, j);
			pixel_put(ram->display->mlx_img, i, j, color);
		}
	mlx_put_image_to_window(ram->display->mlx_ptr,
							ram->display->mlx_win->win_ptr, ram->display->mlx_img->img_ptr,
							0, 0);
	return (SUCCESS);
}