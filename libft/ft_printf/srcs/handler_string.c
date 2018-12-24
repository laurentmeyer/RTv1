/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:23:39 by lmeyer            #+#    #+#             */
/*   Updated: 2017/01/02 21:31:24 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
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

static int	utf_bytes(wchar_t w)
{
	int		bits;

	bits = 0;
	while (w)
	{
		++bits;
		w = w >> 1;
	}
	if (bits < 8)
		return (1);
	else if (bits < 12)
		return (2);
	else if (bits < 17)
		return (3);
	else
		return (4);
}

static int	ft_wchartlen(wchar_t *t)
{
	if (*t == 0)
		return (0);
	return (utf_bytes(*t) + ft_wchartlen(t + 1));
}

static char	*ft_wcharttostr(wchar_t *t)
{
	int		i;
	char	*str;
	char	*res;

	if ((res = ft_strnew(ft_wchartlen(t))))
	{
		i = -1;
		while (t[++i])
		{
			str = ft_wcrtoutf(t[i]);
			ft_strcpy(res + ft_strlen(res), str);
			free(str);
		}
	}
	return (res);
}

char		*handler_string(t_conv *conv, void *arg)
{
	char	*res;
	t_types	u;

	u.generic = arg;
	if (u.s == NULL)
		res = ft_strdup("(null)");
	else if (conv->modifier != l && conv->precision != ERR)
		res = ft_strndup(u.s, conv->precision);
	else if (conv->modifier != l && conv->precision == ERR)
		res = ft_strdup(u.s);
	else
		res = ft_wcharttostr(u.ls);
	res = apply_padding(conv, res);
	return (res);
}
