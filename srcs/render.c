#include "rtv1.h"
#include "raytracer.h"
#include "ft_math.h"
#include <float.h>
#include <stdio.h> //

void			screen_to_world(t_ram *ram, t_ray *ray, int x, int y)
{
	if (x == WIN_W / 2 && y == WIN_H / 2)
		x = WIN_W / 2;
	ray->origin = ram->scene->camera.position;
	ray->direction.x = lerp_double(ram->scene->camera.up_left.x,
				ram->scene->camera.down_right.x, (double)x / WIN_W);
	ray->direction.y = lerp_double(ram->scene->camera.up_left.y,
				ram->scene->camera.down_right.y, (double)y / WIN_H);
				// a optimiser avec ajout de constantes au lieu de lerp
	ray->direction.z = ram->scene->camera.eye_distance;
}

void			apply_inverse_transform(t_hit *hit)
{
	t_v3	inverse_scale;

	inverse_scale = (t_v3){1 / hit->object->scale.x,
			1 / hit->object->scale.y, 1 / hit->object->scale.z };
	hit->normal = scale(hit->normal, inverse_scale);
	hit->normal = rotate_x(hit->normal, hit->object->rotation.x);
	hit->normal = rotate_y(hit->normal, hit->object->rotation.y);
	hit->normal = rotate_z(hit->normal, hit->object->rotation.z);
	hit->point = scale(hit->point, hit->object->scale);
	hit->point = rotate_x(hit->normal, hit->object->rotation.x);
	hit->point = rotate_y(hit->normal, hit->object->rotation.y);
	hit->point = rotate_z(hit->normal, hit->object->rotation.z);
	hit->point = translate(hit->normal, hit->object->position);
}

int			closest_intersection(t_scene *scene, t_ray *ray, t_hit *dst)
{
	size_t			i;
	double			d;
	double			min_dist;
	t_hit			tmp;
	
	min_dist = DBL_MAX;
	i = 0;
	while (i < scene->objects_count)
	{
		if ((d = get_collision(&tmp, *ray, scene->objects[i])) > 0.
			&& d < min_dist)
		{
			min_dist = d;
			*dst = tmp;
		}
		++i;
	}
	if (!(min_dist < DBL_MAX && min_dist > 0.))
		return (0);
	// apply_inverse_transform(dst);
	return (1);
}

unsigned int	normal_color(t_v3 *normal)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = (int)(0xFF * (normal->x + 1.) / 2.);
	green = (int)(0xFF * (normal->y + 1.) / 2.);
	blue = (int)(0xFF * (normal->z + 1.) / 2.);
	return ((unsigned int)(red << 16 | green << 8 | blue));
}

unsigned int	render_pixel(t_ram *ram, int x, int y)
{
	t_ray			ray;
	t_hit			hit;
	unsigned int	color;
	double			shade;

	screen_to_world(ram, &ray, x, y);
	if (closest_intersection(ram->scene, &ray, &hit))
	{
		// color = normal_color(&(hit.normal));
		shade = dot_product(ram->scene->lights[0]->direction, hit.normal);
		if (shade < 0)
			shade = 0;
		color = lerp_color(hit.object->color, (0.2 + 0.8 * shade));
		return (color);
	}
	return (0x0);
}

int render_scene(t_ram *ram)
{
	t_image *img;

	img = ram->display->mlx_img;
	for (int i = 0; i < WIN_W; i++)
		for (int j = 0; j < WIN_H; j++)
			pixel_put(ram->display->mlx_img, i, j, render_pixel(ram, i, j));
	mlx_put_image_to_window(ram->display->mlx_ptr,
							ram->display->mlx_win->win_ptr, ram->display->mlx_img->img_ptr,
							0, 0);
	return (SUCCESS);
}