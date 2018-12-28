#include "libft.h"

double		ft_atof(char *s)
{
	int				integer;
	int				decimal;
	int				after_point;

	integer = ft_atoi(s);
	while (*s != 0 && *s != '.')
		++s;
	decimal = ('.' == *s) ? ft_atoi(s + 1) : 0;
	if (0 == decimal)
		return ((double)integer);
	after_point = 1;
	while (after_point < decimal)
		after_point *= 10;
	return ((double)integer + (double)decimal / after_point);
}
