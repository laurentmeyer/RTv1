#ifndef COLOR_H
# define COLOR_H

#include "geometry.h"

typedef t_v3 		t_color;

void				color_of_int(t_color *out, unsigned int *in);
void				int_of_color(unsigned int *out, t_color *in);
t_color				add_color(t_color a, t_color b);

#endif