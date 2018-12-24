/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:39:19 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:39:24 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (!n)
		return (NULL);
	else if ((*(unsigned char *)dst = *(unsigned char *)src)
					!= (unsigned char)c)
		return (ft_memccpy(dst + 1, src + 1, c, n - 1));
	else
		return (++dst);
}
