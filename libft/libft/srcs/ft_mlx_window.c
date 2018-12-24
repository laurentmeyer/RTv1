/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:28:09 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 20:28:10 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_mlx.h"
#include <stdlib.h>

t_window	*init_window(void *mlx_ptr, int w, int h, char *name)
{
	t_window	*win;

	if (NULL == (win = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	ft_bzero(win, sizeof(t_window));
	if (NULL == (win->name = ft_strdup(name)))
		return (NULL);
	if (NULL == (win->win_ptr = mlx_new_window(mlx_ptr, w, h, name)))
		return (NULL);
	win->w = w;
	win->h = h;
	return (win);
}

void		mlx_free_window(void *mlx_ptr, t_window *win)
{
	if (NULL != win->win_ptr)
		mlx_destroy_window(mlx_ptr, win->win_ptr);
	if (NULL != win->name)
		free(win->name);
	free(win);
}
