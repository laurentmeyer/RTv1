/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:06:57 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:06:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "geometry.h"
# include "object.h"

typedef struct		s_ray
{
	t_v3			origin;
	t_v3			direction;
}					t_ray;

typedef struct		s_hit
{
	t_ray			ray;
	double			t;
	t_v3			point;
	t_v3			normal;
	t_object		*object;
}					t_hit;

typedef int			(*t_hit_f)(t_hit *out, t_ray *ray, t_object *object);
typedef void		(*t_norm_f)(t_hit *out);

int					hit_object(t_hit *out, t_ray ray, t_object *object);
int					hit_sphere(t_hit *out, t_ray *ray, t_object *sphere);
int					hit_plane(t_hit *out, t_ray *ray, t_object *plane);
int					hit_cylinder(t_hit *out, t_ray *ray, t_object *cylinder);
int					hit_cone(t_hit *out, t_ray *ray, t_object *cone);
void				get_normal(t_hit *out, t_ray *ray);
void				normal_plane(t_hit *out);
void				normal_sphere(t_hit *out);
void				normal_cylinder(t_hit *out);
void				normal_cone(t_hit *out);

#endif
