#include "rtv1.h"
#include "raytracer.h"
#include "ft_math.h"

unsigned int	render_pixel(t_ram *ram, int x, int y)
{
	t_ray	ray;
	t_hit	hits[MAX_OBJECTS];
	size_t	i;
	unsigned int color;

	if (x == WIN_W / 2 && y == WIN_H / 2)
		x = WIN_W / 2;
	ray.origin = (t_v4){0., 0., 0., 1.};
	ray.direction.x = lerp_double(ram->scene->camera.up_left.x,
				ram->scene->camera.down_right.x, (double)x / WIN_W);
	ray.direction.y = lerp_double(ram->scene->camera.up_left.y,
				ram->scene->camera.down_right.y, (double)y / WIN_H);
	ray.direction.z = ram->scene->camera.eye_distance;
	ray.direction.w = 1.;
	color = 0x0;
	i = -1;
	while (++i < ram->scene->objects_count)
	{
		get_collision(hits + i, &ray, ram->scene->objects[i]);
		if (hits[i].distance >= 0.)
			color = 0xff;
	}
	return (color);
}

int				render_scene(t_ram *ram)
{
	t_image		*img;

	img = ram->display->mlx_img;
	for (int i = 0; i < WIN_W; i++)
		for (int j = 0; j < WIN_H; j++)
			pixel_put(ram->display->mlx_img,i, j, render_pixel(ram, i, j));
	mlx_put_image_to_window(ram->display->mlx_ptr,
			ram->display->mlx_win->win_ptr, ram->display->mlx_img->img_ptr,
			0, 0);
	return (SUCCESS);
}
