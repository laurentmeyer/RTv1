/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:40:52 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/20 14:03:23 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			get_width(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '.' && !ft_isdigit(s[i]))
		++i;
	if (!s[i] || s[i] == '.')
		return (ERR);
	if (s[i] == '0')
		return (get_width(s + i + 1));
	return (ft_atoi(s + i));
}
