#ifndef GEOMETRY_H
# define GEOMETRY_H

typedef struct		s_v2i
{
	int				x;
	int				y;
}					t_v2i;

typedef struct		s_v3
{
	double			x;
	double			y;
	double			z;
}					t_v3;

t_v3				inverse(t_v3 v);
double				magnitude(t_v3 vector);
t_v3				normalize(t_v3 v);
double				dot_product(t_v3 a, t_v3 b);
t_v3				cross_product(t_v3 a, t_v3 b);
t_v3				translate(t_v3 p, t_v3 t);
t_v3				scale(t_v3 p, t_v3 t);
t_v3				rotate_x(t_v3 p, double radians);
t_v3				rotate_y(t_v3 p, double radians);
t_v3				rotate_z(t_v3 p, double radians);

#endif
