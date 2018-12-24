/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:45:16 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 19:48:41 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_array.h"
#include <stdlib.h>

t_int_array	*upper_percentile(t_int_array *src, int percent)
{
	t_int_array	*res;
	int			keep;

	if (NULL == (res = copy_int_array(src)))
		return (NULL);
	keep = percent * (res->count) / 100;
	if (keep <= 0)
		keep = 1;
	while (res->count > keep)
		int_remove(res, int_index(res, int_min(res)));
	return (res);
}
