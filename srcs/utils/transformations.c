/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:09:59 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:27:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <math.h>

t_v3	translate(t_v3 p, t_v3 t)
{
	t_v3	ret;

	ret = p;
	ret.x += t.x;
	ret.y += t.y;
	ret.z += t.z;
	return (ret);
}

t_v3	scale(t_v3 p, t_v3 t)
{
	t_v3	ret;

	ret = p;
	ret.x *= t.x;
	ret.y *= t.y;
	ret.z *= t.z;
	return (ret);
}

t_v3	rotate_x(t_v3 p, double radians)
{
	t_v3	ret;

	ret.x = p.x;
	ret.y = p.y * cos(radians) - p.z * sin(radians);
	ret.z = p.y * sin(radians) + p.z * cos(radians);
	return (ret);
}

t_v3	rotate_y(t_v3 p, double radians)
{
	t_v3	ret;

	ret.x = p.x * cos(radians) + p.z * sin(radians);
	ret.y = p.y;
	ret.z = -p.x * sin(radians) + p.z * cos(radians);
	return (ret);
}

t_v3	rotate_z(t_v3 p, double radians)
{
	t_v3	ret;

	ret.x = p.x * cos(radians) - p.y * sin(radians);
	ret.y = p.x * sin(radians) + p.y * cos(radians);
	ret.z = p.z;
	return (ret);
}
