/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:26:20 by lmeyer            #+#    #+#             */
/*   Updated: 2017/01/02 21:17:15 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_vprintf(const char *format, va_list ap)
{
	char	*str;
	int		ret;

	if ((ret = ft_vasprintf(&str, format, ap)) == ERR)
		return (ERR);
	write(1, str, ret);
	free(str);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	return (ret);
}
