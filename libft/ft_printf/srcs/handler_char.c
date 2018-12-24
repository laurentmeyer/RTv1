/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:27:24 by lmeyer            #+#    #+#             */
/*   Updated: 2017/01/02 21:28:06 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static char	*apply_padding(t_conv *conv, char *s)
{
	char	*padding;
	char	*position;

	padding = (conv->flags & FLAG_ZERO) ? "0" : " ";
	position = s;
	if (conv->flags & FLAG_MINUS)
		position = ft_strlast(s) + 1;
	while ((int)ft_strlen(s) < conv->width)
	{
		s = ft_insert_str(s, position, position, padding);
		position = s;
		if (conv->flags & FLAG_MINUS)
			position = ft_strlast(s) + 1;
	}
	return (s);
}

char		*handler_char(t_conv *conv, void *arg)
{
	char	*res;
	t_types	u;

	(void)conv;
	u.generic = arg;
	if (u.c == '%')
		res = ft_strdup("%%");
	else if (u.c != 0 && conv->modifier == l)
		res = ft_wcrtoutf(u.lc);
	else
	{
		if (!(res = (char *)malloc(2)))
			return (NULL);
		res[0] = u.c != 0 ? (unsigned char)u.c : 0xFF;
		res[1] = '\0';
	}
	res = apply_padding(conv, res);
	return (res);
}
