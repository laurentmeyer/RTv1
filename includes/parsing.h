/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:06:51 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:42:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "geometry.h"
# include "scene.h"

# define I_LIGHT  0
# define I_OBJECT 1
# define I_CAMERA 2

typedef struct		s_i_object
{
	int				type;
	t_v3			position;
	t_v3			rotation;
	t_v3			scale;
	t_material		material;
}					t_i_object;

typedef struct		s_i_light
{
	int				type;
	t_v3			direction;
	t_v3			position;
	double			intensity;
}					t_i_light;

typedef struct		s_parsing
{
	int				fd;
	char			*line;
	char			**split;
	int				flush;
}					t_parsing;

size_t				count_args(char **args);

#endif
