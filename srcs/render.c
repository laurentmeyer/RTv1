#include "rtv1.h"
#include "ft_math.h"
#include <math.h>

int						render_scene(t_ram *ram)
{
	t_image		*img;

	img = ram->display->mlx_img;
	for (int i = 30; i < 200; i++)
		for (int j = 30; j < 200; j++)
			pixel_put(img, i, j, 0xff0000);
	mlx_put_image_to_window(ram->display->mlx_ptr,
			ram->display->mlx_win->win_ptr, ram->display->mlx_img->img_ptr,
			0, 0);
	return (SUCCESS);
}
