/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclusions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:44:19 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 19:47:57 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_array.h"
#include <stdlib.h>

t_int_array	*int_not_in(t_int_array *src, t_int_array *exclude)
{
	t_int_array	*res;
	int			i;
	int			index;

	if (NULL == (res = copy_int_array(src)))
		return (NULL);
	i = 0;
	while (i < exclude->count)
	{
		if ((index = int_index(res, (exclude->data)[i])) >= 0)
			int_remove(res, index);
		++i;
	}
	return (res);
}
