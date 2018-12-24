#include "rtv1.h"

#define KEY_PRESS_EVENT 2
#define KEY_RELEASE_EVENT 3
#define CLOSE_WIN_EVENT 17
#define CLOSE_WIN_MASK 1L << 17
#define KEY_PRESS_MASK 1L << 0
#define KEY_RELEASE_MASK 1L << 1
#define ESC_KEY 0x35

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