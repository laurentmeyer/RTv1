/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:49:40 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 19:51:00 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_array.h"
#include <stdlib.h>

t_int_array	*int_values_to_ranks(t_int_array *array)
{
	t_int_array	*tmp;
	t_int_array	*res;
	int			min;
	int			cur;

	if (!(tmp = copy_int_array(array)) ||
		!(res = copy_int_array(array)))
		return (NULL);
	cur = 0;
	while (tmp->count > 0)
	{
		min = int_index(array, int_remove(tmp, int_index(tmp, int_min(tmp))));
		(res->data)[min] = cur++;
	}
	free_int_array(tmp);
	return (res);
}
