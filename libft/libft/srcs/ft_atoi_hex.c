/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:04:04 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/03 17:29:00 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_to_hex(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c + 10 - 'a');
	else if (c >= 'A' && c <= 'F')
		return (c + 10 - 'A');
	else
		return (-1);
}

int			ft_atoi_hex(char *s)
{
	int				l;
	int				p;
	unsigned int	acc;

	if (s[0] != '0' || s[1] != 'x' || (l = ft_strlen(s)) > 8)
		return (0);
	acc = 0;
	p = 1;
	while (l > 2)
	{
		acc = acc + p * char_to_hex(s[l-- - 1]);
		p *= 16;
	}
	return (acc);
}
