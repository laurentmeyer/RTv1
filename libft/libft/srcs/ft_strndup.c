/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 20:55:02 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/16 21:17:49 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char					*ft_strndup(const char *s1, size_t n)
{
	char	*new;
	size_t	i;

	i = ft_strlen(s1) < n ? ft_strlen(s1) : n;
	if ((new = (char *)malloc(n)))
		(ft_strncpy(new, s1, i))[i] = '\0';
	return (new);
}
