/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:23:08 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/02 16:49:22 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **alst)
{
	t_list	*new;
	t_list	*cpy;

	new = NULL;
	cpy = *alst;
	while (cpy)
		ft_lstadd(&new, ft_lstpop(&cpy));
	*alst = new;
}
