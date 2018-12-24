/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:11:59 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/12 17:12:02 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*str;
	int		ret;

	if ((ret = ft_vasprintf(&str, format, ap)) == ERR)
		return (ERR);
	write(fd, str, ret);
	free(str);
	return (ret);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}
