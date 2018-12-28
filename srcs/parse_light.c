#include "parsing.h"
#include "libft.h"
#include "get_next_line.h"
#include "rtv1.h"
#include "object.h"

int		parse_light(t_ram *ram)
{
	static t_light	*light = NULL;
	char			**args;

	ft_putstr("light\n");
	args = ram->parsing.split;
	if (NULL == args)
	{
		if (NULL != light && MAX_LIGHTS == ram->scene->lights_count)
			exit_message(ram, ERROR, "Maximum number of objects reached\n");
		else if (NULL != light)
			ram->scene->lights[(ram->scene->lights_count++)] = light;
		light = NULL;
	}
	else if (2 == count_args(args) && 0 == ft_strcmp(args[0], "light"))
		light = new_light((t_v3){0., 0., 0.}, 1.);
	else
		return (ERROR);
	return (SUCCESS);
}