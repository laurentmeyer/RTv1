/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:25:17 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/20 14:01:41 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static char		*requalify_conversion(char *s)
{
	char	*conv;

	conv = ft_strlast(s);
	if (*conv == 'i')
		return (ft_insert_str(s, conv, conv + 1, "d"));
	if (*conv == 'D')
		return (ft_insert_str(s, conv, conv + 1, "ld"));
	else if (*conv == 'U')
		return (ft_insert_str(s, conv, conv + 1, "lu"));
	else if (*conv == 'O')
		return (ft_insert_str(s, conv, conv + 1, "lo"));
	else if (*conv == 'S')
		return (ft_insert_str(s, conv, conv + 1, "ls"));
	else if (*conv == 'C')
		return (ft_insert_str(s, conv, conv + 1, "lc"));
	else
		return (s);
}

t_conv			*new_conversion(char *start, int len)
{
	t_conv	*new;
	char	*s;

	if (!(s = ft_strndup(start, len))
			|| !(s = requalify_conversion(s)))
		return (NULL);
	if ((new = (t_conv *)malloc(sizeof(t_conv))))
	{
		new->conversion = *(ft_strlast(s));
		new->modifier = get_modifier(s);
		new->flags = get_flags(s);
		new->precision = get_precision(s);
		new->width = get_width(s);
	}
	free(s);
	return (new);
}

int				find_next_conversion(char *format, char **start, char **end)
{
	char	*tmp;
	int		i;

	if (!(tmp = ft_strchr(format, '%')))
		return (0);
	if (tmp[1] == '%')
		return (find_next_conversion(tmp + 2, start, end));
	i = 1;
	while (tmp[i] && ft_strchr(ACCEPTABLE, tmp[i]))
		++i;
	if (tmp[i] && ft_strchr(CONVERSIONS, tmp[i]))
	{
		*start = tmp;
		*end = tmp + i;
		return (1);
	}
	if (tmp[i] == '\0')
		*tmp = '\0';
	else
		ft_memmove(tmp, tmp + i, ft_strlen(tmp));
	return (0);
}
