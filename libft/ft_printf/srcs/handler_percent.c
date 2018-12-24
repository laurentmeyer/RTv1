/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:26:48 by lmeyer            #+#    #+#             */
/*   Updated: 2017/01/02 21:26:39 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*apply_padding(t_conv *conv, char *s)
{
	char	*padding;
	char	*position;

	if (conv->width == ERR)
		return (s);
	padding = (conv->flags & FLAG_ZERO) ? "0" : " ";
	position = (conv->flags & FLAG_MINUS) ? ft_strlast(s) + 1 : s;
	while ((int)ft_strlen(s) < conv->width + 1)
	{
		s = ft_insert_str(s, position, position, padding);
		position = (conv->flags & FLAG_MINUS) ? ft_strlast(s) + 1 : s;
	}
	return (s);
}

char		*handler_percent(t_conv *conv, void *arg)
{
	char	*s;

	(void)arg;
	s = ft_strdup("%%");
	s = apply_padding(conv, s);
	return (s);
}
