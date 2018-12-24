/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:29:24 by lmeyer            #+#    #+#             */
/*   Updated: 2017/01/02 21:29:58 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*apply_padding(t_conv *conv, char *s)
{
	char	*padding;
	char	*position;

	padding = (conv->flags & FLAG_ZERO) ? "0" : " ";
	position = s;
	if (conv->flags & FLAG_MINUS)
		position = ft_strlast(s) + 1;
	else if (conv->flags & FLAG_ZERO && s[0] == '0'
			&& (s[1] == 'x' || s[1] == 'X'))
		position = s + 2;
	else if (conv->flags & FLAG_ZERO && (s[0] == '+' || s[0] == '-'))
		position = s + 1;
	while ((int)ft_strlen(s) < conv->width)
	{
		s = ft_insert_str(s, position, position, padding);
		position = s;
		if (conv->flags & FLAG_MINUS)
			position = ft_strlast(s) + 1;
		else if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
			position = s + 2;
		else if (s[0] == '+' || s[0] == '-')
			position = s + 1;
	}
	return (s);
}

char		*handler_pointer(t_conv *conv, void *arg)
{
	char	*res;
	t_types u;

	if ((u.generic = arg) == NULL && conv->precision == 0)
		res = ft_strdup("");
	else
		res = ft_itoa_base_max_unsigned((uintmax_t)(u.llu), 16);
	res = ft_insert_str(res, res, res, "0X");
	ft_strtolower(res);
	res = apply_padding(conv, res);
	return (res);
}
