#include "libft.h"
#include <stdio.h> //

size_t		ft_index(char **haystack, char *needle)
{
	size_t	i;

	i = 0;
	while (haystack[i])
	{
		if (0 == ft_strcmp(haystack[i], needle))
			return (i);
		++i;
	}
	return (-1);
}
