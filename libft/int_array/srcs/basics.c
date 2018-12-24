/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:39:26 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 19:42:40 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_array.h"

int		int_index(t_int_array *array, int i)
{
	int	j;

	j = 0;
	while (j < array->count)
	{
		if ((array->data)[j] == i)
			return (j);
		j++;
	}
	return (-1);
}

void	int_set(t_int_array *array, int position, int value)
{
	(array->data)[position] = value;
	if (array->count < position + 1)
		array->count = position + 1;
}

int		int_get(t_int_array *array, int index)
{
	return ((array->data)[index]);
}

int		int_first(t_int_array *array)
{
	return (int_get(array, 0));
}

int		int_last(t_int_array *array)
{
	return (int_get(array, array->count - 1));
}
