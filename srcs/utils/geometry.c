/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:09:55 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:22:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <math.h>

t_v3				add_v3(t_v3 a, t_v3 b)
{
	return ((t_v3){ a.x + b.x, a.y + b.y, a.z + b.z });
}

t_v3				sub_v3(t_v3 a, t_v3 b)
{
	return ((t_v3){ a.x - b.x, a.y - b.y, a.z - b.z });
}

t_v3				mul_v3(t_v3 a, double b)
{
	return ((t_v3){ a.x * b, a.y * b, a.z * b });
}

t_v3				div_v3(t_v3 a, double b)
{
	return (mul_v3(a, 1. / b));
}
