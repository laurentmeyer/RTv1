/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:06:44 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:25:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "geometry.h"
# include "color.h"

# define DIRECTIONAL 0
# define SPOT        1

typedef	struct		s_material
{
	t_color			color;
	double			phong_exponent;
	double			diffuse;
	double			specular;
}					t_material;

typedef struct		s_object
{
	void			*hit_f;
	void			*norm_f;
	t_v3			position;
	t_v3			direction;
	t_v3			scale;
	t_material		material;
}					t_object;

typedef struct		s_camera
{
	t_v3			position;
	t_v3			rotation;
	double			eye_distance;
	double			h_fov;
	t_v3			up_left;
	t_v3			pixel_steps;
}					t_camera;

typedef struct		s_light
{
	int				type;
	t_v3			direction;
	t_v3			position;
	double			intensity;
}					t_light;

t_object			*new_object(char *type);
void				destroy_object(t_object *obj);
t_light				*new_light(int type);
void				destroy_light(t_light *light);

#endif
