/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 11:39:32 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/14 11:39:33 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *to_append)
{
	t_list	*cur;

	if (!*alst)
	{
		*alst = to_append;
		return ;
	}
	cur = *alst;
	while (cur->next)
		cur = cur->next;
	cur->next = to_append;
}
