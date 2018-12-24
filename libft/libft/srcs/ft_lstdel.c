/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:39:55 by lmeyer            #+#    #+#             */
/*   Updated: 2017/09/05 13:08:44 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if ((*alst)->next == NULL)
		ft_lstdelone(alst, del);
	else
	{
		tmp = (*alst)->next->next;
		del((*alst)->next->content, (*alst)->next->content_size);
		free((*alst)->next);
		(*alst)->next = tmp;
		ft_lstdel(alst, del);
	}
}
