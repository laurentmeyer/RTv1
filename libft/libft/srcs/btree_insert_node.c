/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 22:14:53 by lmeyer            #+#    #+#             */
/*   Updated: 2017/09/12 22:15:31 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static inline void		insert_right(t_btree **root, t_btree *node)
{
	t_btree	*tmp;

	if ((tmp = ((*root)->right)))
	{
		node->right = tmp;
		tmp->parent = node;
	}
	(*root)->right = node;
	node->parent = *root;
}

static inline void		insert_left(t_btree **root, t_btree *node)
{
	t_btree	*tmp;

	if ((tmp = ((*root)->left)))
	{
		node->left = tmp;
		tmp->parent = node;
	}
	(*root)->left = node;
	node->parent = *root;
}

void					btree_insert_node(t_btree **root, t_btree *node,
		int (*cmpf)(void *, void *))
{
	t_btree	*tmp;

	if (!*root)
		*root = node;
	else if ((*cmpf)((*root)->item, node->item) <= 0)
	{
		if (!(tmp = (*root)->right) || (*cmpf)(tmp->item, node->item) <= 0)
			insert_right(root, node);
		else
			btree_insert_node(&tmp, node, cmpf);
	}
	else
	{
		if (!(tmp = (*root)->left) || (*cmpf)(tmp->item, node->item) > 0)
			insert_left(root, node);
		else
			btree_insert_node(&tmp, node, cmpf);
	}
}
