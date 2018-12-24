/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:39:09 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:39:11 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (*(unsigned char *)s1 != *(unsigned char *)s2)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	else
		return (ft_memcmp(++s1, ++s2, --n));
}
