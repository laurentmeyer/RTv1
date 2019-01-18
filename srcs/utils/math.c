/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:09:57 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:09:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <math.h>

double	lerp_double(double a, double b, double p)
{
	return (a + p * (b - a));
}

double	radians(double degrees)
{
	return (degrees * M_PI / 180.);
}
