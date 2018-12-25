#include "ft_math.h"
#include <math.h>

double	lerp_double(double a, double b, double p)
{
	return (a + p * (b - a));
}
