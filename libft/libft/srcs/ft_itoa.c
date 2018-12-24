/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:40:09 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/12 15:57:54 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*tmp;
	int		l;

	l = ft_intlen(n);
	if (n == MININT)
		tmp = ft_strdup(MININTSTR);
	else if ((tmp = ft_strnew(l)))
	{
		if (n < 0)
		{
			tmp[0] = '-';
			n = -n;
		}
		while (n >= 10)
		{
			tmp[--l] = n % 10 + '0';
			n /= 10;
		}
		tmp[--l] = n % 10 + '0';
	}
	return (tmp);
}
