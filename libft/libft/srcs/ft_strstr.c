/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:35:43 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:35:50 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	if (ft_strlen(big) < ft_strlen(little))
		return (NULL);
	else if (*little == '\0'
			|| ft_strncmp(big, little, ft_strlen(little)) == 0)
		return ((char *)big);
	else
		return (ft_strstr(++big, little));
}
