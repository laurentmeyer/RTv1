/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:39:31 by lmeyer            #+#    #+#             */
/*   Updated: 2016/11/04 15:39:33 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*c;

	if ((new = (t_list *)malloc(sizeof(t_list))))
	{
		new->next = NULL;
		if (!content)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			if ((c = ft_memalloc(content_size)) == NULL)
			{
				free(new);
				return (NULL);
			}
			new->content = ft_memcpy(c, content, content_size);
			new->content_size = content_size;
		}
	}
	return (new);
}
