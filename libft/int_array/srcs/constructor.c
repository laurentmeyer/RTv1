/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:52:09 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 19:52:25 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_array.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void		reallocate(t_int_array *array)
{
	int	i;
	int	*data;

	if (array->capacity < array->count)
		array->capacity = array->count;
	i = 1;
	while (i <= array->capacity)
		i *= 2;
	if (NULL == (data = (int *)malloc(i * sizeof(int))))
	{
		ft_putstr_fd("could not reallocate array\n", STDERR_FILENO);
		exit(0);
	}
	i = 0;
	while (i < array->count)
	{
		data[i] = (array->data)[i];
		i++;
	}
	free(array->data);
	array->data = data;
}

t_int_array	*new_int_array(int capacity)
{
	t_int_array	*res;
	int			i;

	if (NULL == (res = (t_int_array *)malloc(sizeof(t_int_array))))
		return (NULL);
	i = 1;
	while (i < capacity)
		i *= 2;
	if (NULL == (res->data = (int *)malloc(i * sizeof(int))))
		return (NULL);
	res->capacity = i;
	res->count = 0;
	return (res);
}

t_int_array	*copy_int_array(t_int_array *src)
{
	t_int_array	*res;

	if (NULL == (res = (t_int_array *)malloc(sizeof(t_int_array))))
		return (NULL);
	if (NULL == (res->data = (int *)malloc(src->capacity * sizeof(int))))
		return (NULL);
	res->capacity = src->capacity;
	res->count = src->count;
	ft_memcpy(res->data, src->data, res->count * sizeof(int));
	return (res);
}

void		free_int_array(t_int_array *array)
{
	free(array->data);
	free(array);
}
