/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:30:45 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:31:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_index(char **haystack, char *needle)
{
	size_t	i;

	i = 0;
	while (haystack[i])
	{
		if (0 == ft_strcmp(haystack[i], needle))
			return (i);
		++i;
	}
	return (-1);
}
