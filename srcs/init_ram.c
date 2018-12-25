#include "rtv1.h"
#include <stdlib.h>

t_ram	*init_ram(void)
{
	t_ram *ram;

	if (NULL == (ram = (t_ram *)malloc(sizeof(t_ram))))
		exit_message(ram, ERROR, "Could not initialize RAM\n");
	ft_bzero(ram, sizeof(t_ram));
	init_display(ram);
	init_scene(ram);
	init_hooks(ram);
	return (ram);
}

void	free_ram(t_ram *ram)
{
	if (NULL != ram->scene)
		free_scene(ram->scene);
	if (NULL != ram->display)
		free_display(ram->display);
	free(ram);
}
