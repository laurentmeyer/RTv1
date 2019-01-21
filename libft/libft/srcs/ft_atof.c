/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:30:40 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/19 15:12:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline double		decimal_part(char const *s)
{
	char			buf[9];
	int				l;
	unsigned int	pow;

	if (!s || 0 == *s)
		return (0.);
	ft_strncpy(buf, s, 8);
	pow = 1;
	l = ft_strlen(buf);
	while (l-- > 0)
		pow *= 10;
	return ((double)ft_atoi(buf) / pow);
}

double						ft_atof(char const *s)
{
	int		integer;
	double	decimal;
	int		negative;

	while (*s == ' ' || *s == '\t')
		++s;
	negative = (*s == '-');
	integer = ft_atoi(s);
	while (*s != 0 && *s != '.')
		++s;
	if ('.' != *s)
		return ((double)integer);
	decimal = decimal_part(s + 1);
	if (integer < 0 || negative)
		return ((double)integer - decimal);
	return ((double)integer + decimal);
}
