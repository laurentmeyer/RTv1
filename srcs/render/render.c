/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:09:45 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:42:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "raytracer.h"
#include "ft_math.h"
#include "color.h"
#include "scene.h"
#include <float.h>

void			screen_to_world(t_ram *ram, t_ray *ray, int x, int y)
{
	if (x == WIN_W / 2 && y == WIN_H / 2)
		x = WIN_W / 2;
	ray->origin = ram->scene->camera.position;
	ray->direction.x = ram->scene->camera.up_left.x +
						x * ram->scene->camera.pixel_steps.x;
	ray->direction.y = ram->scene->camera.up_left.y +
						y * ram->scene->camera.pixel_steps.y;
	ray->direction.z = ram->scene->camera.up_left.z;
	ray->direction = rotate_x(ray->direction,
								radians(ram->scene->camera.rotation.x));
	ray->direction = rotate_y(ray->direction,
								radians(ram->scene->camera.rotation.y));
	ray->direction = rotate_z(ray->direction,
								radians(ram->scene->camera.rotation.z));
	ray->direction = normalize(ray->direction);
}

int				closest_intersection(
					t_scene *scene,
					t_ray *const ray,
					t_hit *dst)
{
	size_t			i;
	t_hit			tmp;
	t_hit_f			fun;
	int				found;
	double			max_dist;

	max_dist = ray->max_length;
	i = 0;
	found = FALSE;
	while (i < scene->objects_count)
	{
		fun = (t_hit_f)(scene->objects[i]->hit_f);
		if ((*fun)(&tmp, ray, scene->objects[i]) && tmp.t < max_dist
				&& tmp.t > EPSILON)
		{
			max_dist = tmp.t;
			if (NULL == dst)
				return (TRUE);
			*dst = tmp;
			dst->object = scene->objects[i];
			found = TRUE;
		}
		++i;
	}
	return (found);
}

void			render_pixel(unsigned int *out, t_ram *ram, int x, int y)
{
	t_ray		ray;
	t_hit		hit;
	t_color		color;
	t_norm_f	fun;

	screen_to_world(ram, &ray, x, y);
	ray.max_length = DBL_MAX;
	color = (t_color){0., 0., 0.};
	if (closest_intersection(ram->scene, &ray, &hit))
	{
		hit.point = add_v3(ray.origin, mul_v3(ray.direction, hit.t));
		hit.ray = ray;
		fun = (t_norm_f)hit.object->norm_f;
		(*fun)(&hit);
		shade_pixel(ram, &hit, &ray, &color);
	}
	int_of_color(out, &color);
}

int				render_scene(t_ram *ram)
{
	t_image			*img;
	unsigned int	color;
	int				i[2];

	img = ram->display->mlx_img;
	i[0] = -1;
	while (++i[0] < WIN_W)
	{
		i[1] = -1;
		while (++i[1] < WIN_H)
		{
			render_pixel(&color, ram, i[0], i[1]);
			pixel_put(ram->display->mlx_img, i[0], i[1], color);
		}
	}
	mlx_put_image_to_window(ram->display->mlx_ptr,
							ram->display->mlx_win->win_ptr,
							ram->display->mlx_img->img_ptr,
							0, 0);
	return (SUCCESS);
}
