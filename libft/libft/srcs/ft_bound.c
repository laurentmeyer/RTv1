/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bounds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:36:11 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:37:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_bound(double min, double max, double cand)
{
	if (min > max)
		return (cand);
	if (cand < min)
		return (min);
	if (cand > max)
		return (max);
	return (cand);
}
