#include "geometry.h"

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

	ret = p;
	radians = 0;
	return(ret);
}

t_v4	rotate_y(t_v4 p, double radians)
{
	t_v4	ret;

	ret = p;
	radians = 0;
	return(ret);
}

t_v4	rotate_z(t_v4 p, double radians)
{
	t_v4	ret;

	ret = p;
	radians = 0;
	return(ret);
}