#include "rtv1.h"
#include "parsing.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void		free_parsing(t_parsing *parsing)
{
	// ft_putstr("freeing parsing\n");
	if (parsing->fd > 2)
		close(parsing->fd);
	if (NULL != parsing->line)
		free(parsing->line);
	if (NULL != parsing->split)
		ft_free_strsplit(&(parsing->split));
}
