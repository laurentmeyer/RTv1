/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:16:05 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/12 17:31:34 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

int		ft_vsprintf(char *str, const char *format, va_list ap)
{
	int		ret;
	char	*tmp;

	if ((ret = ft_vasprintf(&tmp, format, ap)) == ERR)
		return (ERR);
	ft_strcpy(str, tmp);
	free(tmp);
	return (ret);
}

int		ft_sprintf(char *str, const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (ret);
}
