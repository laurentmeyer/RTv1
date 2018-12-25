#ifndef GEOMETRY_H
# define GEOMETRY_H

typedef struct		s_v4
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_v4;

double				magnitude_v4(t_v4 vector);
double				dot_product_v4(t_v4 a, t_v4 b);
t_v4				cross_product_v4(t_v4 a, t_v4 b);

#endif
