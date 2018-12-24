/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcrtoutf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:02:18 by lmeyer            #+#    #+#             */
/*   Updated: 2017/01/02 21:02:22 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			utf_bytes(wchar_t w)
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

char				*ft_wcrtoutf(wchar_t w)
{
	char	*str;
	int		bits;
	int		i;

	if (((w > 0xD7FF && w < 0xE000) || w > 0x10FFFF) || !(str = ft_strnew(4)))
		return (NULL);
	if ((bits = utf_bytes(w)) == 1)
	{
		str[0] = (unsigned char)w;
		return (ft_strdup(str));
	}
	i = bits;
	while (i > 1)
	{
		str[i-- - 1] = (1 << 7) | (w & ~(1 << 6));
		w = w >> 6;
	}
	str[0] = (~0 << (8 - bits)) | (unsigned char)w;
	return (str);
}
