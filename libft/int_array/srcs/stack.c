/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:50:22 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 19:50:23 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_array.h"

int		int_pop(t_int_array *array)
{
	array->count -= 1;
	return ((array->data)[array->count]);
}

void	int_push(t_int_array *array, int i)
{
	if (array->count >= array->capacity)
		reallocate(array);
	(array->data)[array->count] = i;
	array->count += 1;
}

void	int_unshift(t_int_array *array, int value)
{
	int	i;

	if (array->count >= array->capacity)
		reallocate(array);
	i = array->count;
	while (i > 0)
	{
		(array->data)[i] = (array->data)[i - 1];
		--i;
	}
	(array->data)[0] = value;
	array->count += 1;
}
