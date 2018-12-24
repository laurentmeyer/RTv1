/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:35:57 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:44:46 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

char	*ft_strrchr(const char *s, int c)
{
	if ((char)c == '\0')
		return (ft_strchr(s, c));
	else if (!ft_strchr(s, c))
		return (NULL);
	else if (!ft_strchr(ft_strchr(s, c) + 1, c))
		return (ft_strchr(s, c));
	else
		return (ft_strrchr(ft_strchr(s, c) + 1, c));
}
