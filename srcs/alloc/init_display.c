/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:04:51 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:04:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "display.h"
#include "ft_mlx.h"
#include <stdlib.h>

void		init_display(t_ram *ram)
{
	t_display	*d;

	if (NULL == (d = (t_display *)malloc(sizeof(t_display))))
		exit_message(ram, ERROR, "Could not allocate display\n");
	ft_bzero(d, sizeof(t_display));
	if (NULL == (d->mlx_ptr = mlx_init()))
		exit_message(ram, ERROR, "Could not get mlx ptr\n");
	ram->display = d;
	if (NULL == (d->mlx_win = init_window(d->mlx_ptr, WIN_W, WIN_H, WIN_NAME)))
		exit_message(ram, ERROR, "Could not init window\n");
	if (NULL == (d->mlx_img = init_image(d->mlx_ptr, WIN_W, WIN_H)))
		exit_message(ram, ERROR, "Could not init image\n");
}

void		free_display(t_display *display)
{
	if (NULL != display->mlx_win)
		mlx_free_window(display->mlx_ptr, display->mlx_win);
	if (NULL != display->mlx_img)
		mlx_free_image(display->mlx_ptr, display->mlx_img);
	free(display);
}
