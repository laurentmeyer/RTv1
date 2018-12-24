/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:37:04 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:37:08 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tmp;

	if ((tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		ft_strcpy(ft_strcpy(tmp, s1) + ft_strlen(s1), s2);
	return (tmp);
}
