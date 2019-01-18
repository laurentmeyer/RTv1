/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:09:55 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:22:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <math.h>

t_v3				inverse(t_v3 v)
{
	return ((t_v3){-v.x, -v.y, -v.z});
}

double				magnitude(t_v3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_v3				normalize(t_v3 v)
{
	return (mul_v3(v, 1. / magnitude(v)));
}

double				dot_product(t_v3 a, t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_v3				cross_product(t_v3 a, t_v3 b)
{
	return ((t_v3){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x - b.z,
		a.x * b.y - a.y * b.z });
}
