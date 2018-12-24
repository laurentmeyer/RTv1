/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:36:40 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:36:47 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tmp;

	if ((tmp = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (s[i])
		{
			tmp[i] = (*f)(s[i]);
			++i;
		}
	}
	return (tmp);
}
