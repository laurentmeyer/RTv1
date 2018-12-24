/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:38:54 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:43:24 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static	void	*ft_membcpy(void *dst, const void *src, size_t n)
{
	if (n)
	{
		*((unsigned char *)dst + n - 1) = *((unsigned char *)src + n - 1);
		ft_membcpy(dst, src, --n);
	}
	return (dst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
		return (ft_membcpy(dst, src, len));
	return (ft_memcpy(dst, src, len));
}
