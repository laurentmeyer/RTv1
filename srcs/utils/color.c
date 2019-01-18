/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:09:53 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:21:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void		color_of_int(t_color *out, unsigned int *in)
{
	out->x = (float)((*in & 0xFF0000) >> 16) / 0xFF;
	out->y = (float)((*in & 0xFF00) >> 8) / 0xFF;
	out->z = (float)(*in & 0xFF) / 0xFF;
}

void		int_of_color(unsigned int *out, t_color *in)
{
	*out = (int)(0xFF * in->x) << 16 |
			(int)(0xFF * in->y) << 8 |
			(int)(0xFF * in->z);
}

t_color		add_color(t_color a, t_color b)
{
	t_color	c;

	c.x = a.x + b.x > 1. ? 1. : a.x + b.x;
	c.y = a.y + b.y > 1. ? 1. : a.y + b.y;
	c.z = a.z + b.z > 1. ? 1. : a.z + b.z;
	return (c);
}
