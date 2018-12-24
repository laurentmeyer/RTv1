/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_integers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:05:29 by lmeyer            #+#    #+#             */
/*   Updated: 2017/01/02 21:08:01 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*extra_chars(t_conv *conv, char *s)
{
	char	*digit;

	if (conv->precision == ERR)
		conv->precision = 1;
	else if (conv->precision == 0 && ft_strequ(s, "0"))
		*s = '\0';
	digit = (*s == '-') ? s + 1 : s;
	while ((int)ft_strlen(digit) < conv->precision)
	{
		s = ft_insert_str(s, digit, digit, "0");
		digit = (*s == '-') ? s + 1 : s;
	}
	if ((conv->flags & FLAG_ALTERNATE) && conv->conversion == 'o'
			&& !ft_strequ(s, "0"))
		s = ft_insert_str(s, s, s, "0");
	if ((conv->flags & FLAG_ALTERNATE) && !ft_strequ(s, "0") && !ft_strequ(s,
				"") && (conv->conversion == 'x' || conv->conversion == 'X'))
		s = ft_insert_str(s, s, s, "0X");
	if ((conv->flags & FLAG_PLUS) && conv->conversion == 'd' && *s != '-')
		s = ft_insert_str(s, s, s, "+");
	if ((conv->flags & FLAG_SPACE) && conv->conversion == 'd' && *s != '-')
		s = ft_insert_str(s, s, s, " ");
	return (s);
}

static char	*apply_padding(t_conv *conv, char *s)
{
	char	*padding;
	char	*position;

	padding = (conv->flags & FLAG_ZERO) ? "0" : " ";
	position = s;
	if (conv->flags & FLAG_MINUS)
		position = ft_strlast(s) + 1;
	else if (conv->flags & FLAG_ZERO && *s == '0' &&
			(s[1] == 'x' || s[1] == 'X'))
		position = s + 2;
	else if (conv->flags & FLAG_ZERO && (*s == '+' || *s == ' ' || *s == '-'))
		position = s + 1;
	while ((int)ft_strlen(s) < conv->width)
	{
		s = ft_insert_str(s, position, position, padding);
		position = s;
		if (conv->flags & FLAG_MINUS)
			position = ft_strlast(s) + 1;
		else if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
			position = s + 2;
		else if (s[0] == '+' || s[0] == ' ' || s[0] == '-')
			position = s + 1;
	}
	return (s);
}

static char	*handler_signed_integers(t_conv *conv, void *arg)
{
	t_types	u;
	char	*res;

	u.generic = arg;
	if (conv->modifier == hh)
		res = ft_itoa_base_max_signed((intmax_t)(u.hhd), 10);
	else if (conv->modifier == h)
		res = ft_itoa_base_max_signed((intmax_t)(u.hd), 10);
	else if (conv->modifier == l)
		res = ft_itoa_base_max_signed((intmax_t)(u.ld), 10);
	else if (conv->modifier == ll)
		res = ft_itoa_base_max_signed((intmax_t)(u.lld), 10);
	else if (conv->modifier == j)
		res = ft_itoa_base_max_signed((intmax_t)(u.jd), 10);
	else if (conv->modifier == z)
		res = ft_itoa_base_max_signed((intmax_t)(u.zd), 10);
	else
		res = ft_itoa_base_max_signed((intmax_t)(u.d), 10);
	return (res);
}

static char	*handler_unsigned_integers(t_conv *conv, void *arg)
{
	t_types	u;
	char	*res;
	int		base;

	u.generic = arg;
	base = 16;
	if (conv->conversion == 'u' || conv->conversion == 'o')
		base = conv->conversion == 'u' ? 10 : 8;
	if (conv->modifier == hh)
		res = ft_itoa_base_max_unsigned((uintmax_t)(u.hhu), base);
	else if (conv->modifier == h)
		res = ft_itoa_base_max_unsigned((uintmax_t)(u.hu), base);
	else if (conv->modifier == l)
		res = ft_itoa_base_max_unsigned((uintmax_t)(u.lu), base);
	else if (conv->modifier == ll)
		res = ft_itoa_base_max_unsigned((uintmax_t)(u.llu), base);
	else if (conv->modifier == j)
		res = ft_itoa_base_max_unsigned((uintmax_t)(u.ju), base);
	else if (conv->modifier == z)
		res = ft_itoa_base_max_unsigned((uintmax_t)(u.zu), base);
	else
		res = ft_itoa_base_max_unsigned((uintmax_t)(u.u), base);
	return (res);
}

char		*handler_integers(t_conv *conv, void *arg)
{
	t_types	u;
	char	*res;

	u.generic = arg;
	if (conv->conversion == 'd')
		res = handler_signed_integers(conv, arg);
	else
		res = handler_unsigned_integers(conv, arg);
	res = extra_chars(conv, res);
	res = apply_padding(conv, res);
	if (conv->conversion == 'x')
		ft_strtolower(res);
	return (res);
}
