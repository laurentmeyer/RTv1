/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:18:13 by lmeyer            #+#    #+#             */
/*   Updated: 2017/01/02 21:18:45 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	ft_hex(int i)
{
	if (i >= 0 && i <= 9)
		return ('0' + i);
	return ('A' + i - 10);
}

char		*ft_itoa_base_max_unsigned(uintmax_t value, int base)
{
	char	*rev;
	int		i;
	char	*result;

	if (!(rev = (char *)malloc((8 * sizeof(intmax_t) + 1))))
		return (NULL);
	ft_bzero(rev, 8 * sizeof(intmax_t) + 1);
	rev[0] = ft_hex(value % base);
	value /= base;
	i = 0;
	while (value > 0)
	{
		rev[++i] = ft_hex(value % base);
		value /= base;
	}
	result = ft_strrev(rev);
	free(rev);
	return (result);
}

char		*ft_itoa_base_max_signed(intmax_t value, int base)
{
	char	*rev;
	int		i;
	int		sign;
	char	*result;

	if (!(rev = (char *)malloc((8 * sizeof(intmax_t) + 1))))
		return (NULL);
	ft_bzero(rev, 8 * sizeof(intmax_t) + 1);
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
