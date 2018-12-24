/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:37:12 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:37:15 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	if (size <= (i = ft_strlen(dst)))
		return (size + ft_strlen(src));
	ret = i + ft_strlen(src);
	while (i < size - 1 && (dst[i] = *(src++)) != '\0')
		++i;
	if (i == size - 1)
		dst[i] = '\0';
	return (ret);
}
