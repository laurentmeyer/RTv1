#include "geometry.h"
#include <math.h>

t_v3				add_v3(t_v3 a, t_v3 b)
{
	return ((t_v3){ a.x + b.x, a.y + b.y, a.z + b.z });
}

t_v3				sub_v3(t_v3 a, t_v3 b)
{
	return ((t_v3){ a.x - b.x, a.y - b.y, a.z - b.z });
}

t_v3				mul_v3(t_v3 a, double b)
{
	return ((t_v3){ a.x * b, a.y * b, a.z * b });
}

t_v3				div_v3(t_v3 a, double b)
{
	return (mul_v3(a, 1. / b));
}

t_v3	inverse(t_v3 v)
{
	return ((t_v3){- v.x, - v.y, - v.z});
}

double	magnitude(t_v3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_v3	normalize(t_v3 v)
{
	return(mul_v3(v, 1. / magnitude(v)));
}

double	dot_product(t_v3 a, t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_v3	cross_product(t_v3 a, t_v3 b)
{
	return ((t_v3){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x - b.z,
		a.x * b.y - a.y * b.z });
}