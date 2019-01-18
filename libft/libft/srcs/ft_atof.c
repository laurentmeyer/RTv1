/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:30:40 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:30:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(char *s)
{
	int				integer;
	int				decimal;
	int				after_point;

	integer = ft_atoi(s);
	while (*s != 0 && *s != '.')
		++s;
	decimal = ('.' == *s) ? ft_atoi(s + 1) : 0;
	if (0 == decimal)
		return ((double)integer);
	after_point = 1;
	while (after_point <= decimal)
		after_point *= 10;
	if (integer < 0)
		return ((double)integer - (double)decimal / after_point);
	return ((double)integer + (double)decimal / after_point);
}
