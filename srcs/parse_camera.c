#include "parsing.h"
#include "libft.h"
#include "get_next_line.h"
#include "rtv1.h"
#include "object.h"

int		parse_camera(t_ram *ram)
{
	char			**args;

	args = ram->parsing.split;
	ft_putstr("camera\n");
	if (NULL == args)
	;
	else if (4 == count_args(args) && 0 == ft_strcmp(args[0], "position"))
		ram->scene->camera.position = (t_v3){0., 0., 0.};
	return (SUCCESS);
}