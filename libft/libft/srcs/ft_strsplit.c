/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:29:31 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 20:29:39 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		w;

	w = ft_countwords(s, c);
	if ((arr = (char **)malloc((w + 1) * sizeof(char *))))
	{
		i = 0;
		while (i < w)
		{
			while (*s == c)
				++s;
			j = 0;
			while (*(s + j) != '\0' && *(s + j) != c)
				++j;
			if ((arr[i] = ft_strnew(j)))
				ft_strncpy(arr[i++], s, j);
			s += j;
		}
		arr[i] = 0;
	}
	return (arr);
}
