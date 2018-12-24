/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:40:09 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/12 16:02:36 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int res;

	res = 1;
	if (n == MININT)
		return (MININTSIZE);
	else if (n < 0)
		return (1 + ft_intlen(-n));
	while ((n = n / 10))
		++res;
	return (res);
}
