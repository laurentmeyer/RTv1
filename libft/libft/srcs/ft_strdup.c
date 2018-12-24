/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:37:37 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:37:38 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	char	*tmp;

	if ((tmp = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))) == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (ft_strcpy(tmp, s1));
}
