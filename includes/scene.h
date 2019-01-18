/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:07:02 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:07:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "object.h"
# include <stdlib.h>
# define MAX_OBJECTS 12
# define MAX_LIGHTS 2

typedef struct		s_scene
{
	t_camera		camera;
	t_object		*objects[MAX_OBJECTS];
	size_t			objects_count;
	t_light			*lights[MAX_LIGHTS];
	size_t			lights_count;
	double			ambiant_light;
}					t_scene;

#endif
