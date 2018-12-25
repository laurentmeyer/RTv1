#ifndef GEOMETRY_H
# define GEOMETRY_H

typedef struct		s_v2i
{
	int				x;
	int				y;
}					t_v2i;

typedef struct		s_v4
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_v4;

t_v4				inverse(t_v4 v);
double				magnitude_v4(t_v4 vector);
double				dot_product_v4(t_v4 a, t_v4 b);
t_v4				cross_product_v4(t_v4 a, t_v4 b);
t_v4				translate(t_v4 p, t_v4 t);
t_v4				scale(t_v4 p, t_v4 t);
t_v4				rotate_x(t_v4 p, double radians);
t_v4				rotate_y(t_v4 p, double radians);
t_v4				rotate_z(t_v4 p, double radians);

#endif
