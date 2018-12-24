/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 19:54:01 by lmeyer            #+#    #+#             */
/*   Updated: 2017/09/14 10:59:29 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>

typedef	struct			s_btree
{
	struct s_btree		*parent;
	struct s_btree		*left;
	struct s_btree		*right;
	void				*item;
}						t_btree;

t_btree					*btree_create_node(void *item);
void					btree_insert_node(t_btree **root, t_btree *node,
		int (*cmpf)(void *, void *));

#endif
