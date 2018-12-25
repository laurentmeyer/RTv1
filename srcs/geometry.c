#include "geometry.h"
#include <math.h>

t_v4	inverse(t_v4 v)
{
	return ((t_v4){- v.x, - v.y, - v.z, v.w});
}

double	magnitude_v4(t_v4 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double	dot_product_v4(t_v4 a, t_v4 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_v4	cross_product_v4(t_v4 a, t_v4 b)
{
	return ((t_v4){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x - b.z,
		a.x * b.y - a.y * b.z,
		1.});
}