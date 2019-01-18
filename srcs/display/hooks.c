/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:05:15 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:11:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "hooks.h"

static int		leave(t_ram *ram)
{
	exit_message(ram, 0, NULL);
	return (1);
}

static int		key_press(int keycode, t_ram *ram)
{
	if (keycode == ESC_KEY)
		exit_message(ram, 0, NULL);
	return (1);
}

int				init_hooks(t_ram *ram)
{
	mlx_hook(ram->display->mlx_win->win_ptr,
			CLOSE_WIN_EVENT, CLOSE_WIN_MASK, &leave, ram);
	mlx_hook(ram->display->mlx_win->win_ptr,
			KEY_PRESS_EVENT, KEY_PRESS_MASK, &key_press, ram);
	return (SUCCESS);
}
