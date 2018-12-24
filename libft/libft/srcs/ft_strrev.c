/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:07:10 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/22 11:09:09 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (s[i])
		++i;
	if (!(res = (char *)malloc(i + 1)))
		return (NULL);
	res[i] = '\0';
	j = 0;
	while (--i >= 0)
		res[j++] = s[i];
	return (res);
}
