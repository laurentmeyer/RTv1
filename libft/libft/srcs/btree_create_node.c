/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 22:10:48 by lmeyer            #+#    #+#             */
/*   Updated: 2017/10/14 11:38:09 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*res;

	if (!(res = (t_btree *)malloc(sizeof(t_btree))))
		return (NULL);
	res->item = item;
	res->parent = NULL;
	res->left = NULL;
	res->right = NULL;
	return (res);
}
