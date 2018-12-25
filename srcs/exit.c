#include "rtv1.h"
#include <unistd.h>
#include <stdlib.h>

void	exit_message(t_ram *ram, int exit_code, char *message)
{
	if (NULL != ram)
		free_ram(ram);
	if (NULL != message)
		ft_putstr_fd(message, STDERR_FILENO);
	// while (1) ;
	exit(exit_code);
}
