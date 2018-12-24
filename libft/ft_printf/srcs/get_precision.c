/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:31:05 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/21 20:39:36 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		get_precision(char *str)
{
	char	*s;
	int		i;

	if (!(s = ft_strchr(str, '.')))
		return (ERR);
	i = ft_atoi(s + 1);
	return (i >= 0 ? i : ERR);
}
