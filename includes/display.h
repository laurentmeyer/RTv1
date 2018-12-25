#ifndef DISPLAY_H
# define DISPLAY_H

# define WIN_H 480
# define WIN_W 640
# define WIN_NAME "RTv1"

# include "ft_mlx.h"

typedef struct		s_display
{
	void			*mlx_ptr;
	t_window		*mlx_win;
	t_image			*mlx_img;
}					t_display;

#endif
