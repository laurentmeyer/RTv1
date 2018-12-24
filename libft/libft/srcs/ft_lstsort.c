/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:30:10 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/02 16:30:13 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmerge(t_list *m1, t_list *m2, t_listcmp *f)
{
	t_list	*res;

	res = NULL;
	while (m1 && m2)
	{
		if ((*f)(m1, m2) >= 0)
			ft_lstappend(&res, ft_lstpop(&m1));
		else
			ft_lstappend(&res, ft_lstpop(&m2));
	}
	if (!m1)
		ft_lstappend(&res, m2);
	else if (!m2)
		ft_lstappend(&res, m1);
	return (res);
}

void			ft_lstsort(t_list **alst, t_listcmp *f)
{
	t_list	*left;
	t_list	*right;
	size_t	len;
	size_t	i;

	if ((len = ft_lstlen(*alst)) <= 1)
		return ;
	i = 0;
	left = NULL;
	right = NULL;
	while (i < len / 2)
	{
		ft_lstappend(&left, ft_lstpop(alst));
		++i;
	}
	right = *alst;
	ft_lstsort(&left, f);
	ft_lstsort(&right, f);
	*alst = ft_lstmerge(left, right, f);
}
