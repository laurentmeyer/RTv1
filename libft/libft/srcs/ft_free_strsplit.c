/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:26:07 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 20:26:20 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_strsplit(char ***to_free)
{
	char	**as;
	int		i;

	i = 0;
	while (*(as = *to_free + i++))
		ft_strdel(as);
	free(*to_free);
}
