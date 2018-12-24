/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:48:27 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 19:48:28 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_array.h"

void	int_insert(t_int_array *array, int index, int value)
{
	int	i;

	if (index < 0 || index >= array->count)
		return ;
	if (array->count >= array->capacity)
		reallocate(array);
	array->count += 1;
	i = array->count - 1;
	while (i > index)
	{
		(array->data)[i] = (array->data)[i - 1];
		i--;
	}
	(array->data)[index] = value;
}

int		int_remove(t_int_array *array, int index)
{
	int i;
	int res;

	i = index;
	array->count -= 1;
	res = (array->data)[index];
	while (i < array->count)
	{
		(array->data)[i] = (array->data)[i + 1];
		++i;
	}
	return (res);
}
