#include "rtv1.h"
#include <unistd.h>
#include <stdlib.h>

void	exit_message(t_ram *ram, int exit_code, char *message)
{
	if (NULL != message)
		ft_putstr_fd(message, STDERR_FILENO);
	if (NULL != ram)
		free_ram(ram);
	// while (1) ;
	exit(exit_code);
}
