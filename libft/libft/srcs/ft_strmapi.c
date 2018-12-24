/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:36:34 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:36:36 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tmp;

	if ((tmp = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (s[i])
		{
			tmp[i] = (*f)(i, s[i]);
			++i;
		}
	}
	return (tmp);
}
