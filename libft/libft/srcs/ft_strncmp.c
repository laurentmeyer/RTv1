/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:36:23 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:36:25 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0 || (!*s1 && !*s2))
		return (0);
	else if (*(unsigned char *)s1 != *(unsigned char *)s2)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	else
		return (ft_strncmp(++s1, ++s2, --n));
}
