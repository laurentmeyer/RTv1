/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:28:41 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/02 16:28:43 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **elem_addr)
{
	t_list	*ret;

	ret = NULL;
	if (elem_addr && (ret = *elem_addr))
	{
		*elem_addr = ret->next;
		ret->next = NULL;
	}
	return (ret);
}
