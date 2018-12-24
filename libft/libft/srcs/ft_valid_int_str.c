/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_int_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:33:34 by lmeyer            #+#    #+#             */
/*   Updated: 2017/01/05 15:06:59 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static long int		ft_atoi_long(const char *str)
{
	int				i;
	int				sign;
	long int		acc;

	i = 0;
	sign = 1;
	acc = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		acc = 10 * acc - (str[i] - '0');
		i++;
	}
	return (-sign * acc);
}

int					ft_valid_int_str(char *s, int strict)
{
	int			i;
	int			j;
	long int	l;

	i = 0;
	if (strict && !ft_isdigit(s[i]) && s[i] != '-')
		return (0);
	while (s[i] && !ft_isdigit(s[i]))
		++i;
	if (s[i] == '\0')
		return (0);
	j = 0;
	while (ft_isdigit(s[i + j]))
		++j;
	if (strict && s[i + j] != '\0')
		return (0);
	if (j > 10)
		return (0);
	if ((l = ft_atoi_long(s)) > INT_MAX || l < INT_MIN)
		return (0);
	return (1);
}
