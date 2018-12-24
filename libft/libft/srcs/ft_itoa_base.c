/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:11:30 by lmeyer            #+#    #+#             */
/*   Updated: 2017/01/02 21:08:34 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	ft_hex(int i)
{
	if (i >= 0 && i <= 9)
		return ('0' + i);
	return ('A' + i - 10);
}

char	*ft_itoa_base(int value, int base)
{
	char	*rev;
	int		i;
	int		sign;
	char	*result;

	if (!(rev = (char *)malloc(33 * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < 33)
		rev[i++] = '\0';
	sign = (value < 0 && base == 10) ? -1 : 1;
	rev[0] = ft_hex((value % base) * (value < 0 ? -1 : 1));
	value /= (base * (value < 0 ? -1 : 1));
	i = 0;
	while (value > 0)
	{
		rev[++i] = ft_hex(value % base);
		value /= base;
	}
	if (sign == -1)
		rev[++i] = '-';
	result = ft_strrev(rev);
	free(rev);
	return (result);
}
