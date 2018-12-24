/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:36:04 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:36:06 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (ft_strlen(big) < ft_strlen(little) || len < ft_strlen(little))
		return (NULL);
	else if (*little == '\0'
			|| ft_strncmp(big, little, ft_strlen(little)) == 0)
		return ((char *)big);
	else
		return (ft_strnstr(++big, little, --len));
}
