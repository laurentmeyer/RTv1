/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:44:46 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 19:48:07 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_array.h"
#include <limits.h>

int				int_min(t_int_array *array)
{
	int	i;
	int min;
	int	cur;

	i = 0;
	min = INT_MAX;
	while (i < array->count)
	{
		if ((cur = (array->data)[i]) < min)
			min = cur;
		i++;
	}
	return (min);
}

int				int_max(t_int_array *array)
{
	int	i;
	int max;
	int	cur;

	i = 0;
	max = INT_MIN;
	while (i < array->count)
	{
		if ((cur = (array->data)[i]) > max)
			max = cur;
		i++;
	}
	return (max);
}
