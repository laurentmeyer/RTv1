/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:36:27 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:36:30 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	if (n < ft_strlen(s2))
		ft_strncpy(ft_strchr(s1, '\0'), s2, n)[n] = '\0';
	else
		ft_strcpy(ft_strchr(s1, '\0'), s2);
	return (s1);
}
