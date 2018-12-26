#include "geometry.h"
#include <math.h>

t_v4	translate(t_v4 p, t_v4 t)
{
	t_v4	ret;

	ret = p;
	ret.x += t.x;
	ret.y += t.y;
	ret.z += t.z;
	return(ret);
}

t_v4	scale(t_v4 p, t_v4 t)
{
	t_v4	ret;

	ret = p;
	ret.x *= t.x;
	ret.y *= t.y;
	ret.z *= t.z;
	return(ret);
}

t_v4	rotate_x(t_v4 p, double radians)
{
	t_v4	ret;

	ret.x = p.x;
	ret.y = p.y * cos(radians) - p.z * sin(radians);
	ret.z = p.y * sin(radians) + p.z * cos(radians);
	ret.w = 1.;
	return(ret);
}

t_v4	rotate_y(t_v4 p, double radians)
{
	t_v4	ret;

	ret.x = p.x * cos(radians) + p.z * sin(radians);
	ret.y = p.y;
	ret.z = - p.x * sin(radians) + p.z * cos(radians);
	ret.w = 1.;
	return(ret);
}

t_v4	rotate_z(t_v4 p, double radians)
{
	t_v4	ret;

	ret.x = p.x * cos(radians) - p.y * sin(radians);
	ret.y = p.x * sin(radians) + p.y * cos(radians);
	ret.z = p.z;
	ret.w = 1.;
	return(ret);
}