#include "rtv1.h"

int			main(void)
{
	t_ram	*ram;

	ram = init_ram();
	render_scene(ram);
	mlx_loop(ram->display->mlx_ptr);
	return (0);
}
