#include "rtv1.h"
#include "object.h"
#include "scene.h"
#include "ft_math.h"
#include <fcntl.h>

int			main(int ac, char **av)
{
	t_ram	*ram;

	ram = init_ram_pre_parsing();
	if (ac < 2)
		exit_message(ram, -1, "usage: ./rtv1 [scene file]\n");
	if (-1 == (ram->parsing.fd = open(av[1], O_RDONLY)))
		exit_message(ram, -1, "RTv1: wrong scene file path\n");
	parse_file(ram);
	init_ram_post_parsing(ram);
	render_scene(ram);
	mlx_loop(ram->display->mlx_ptr);
	return (0);
}
