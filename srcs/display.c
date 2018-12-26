#include "rtv1.h"
#include "display.h"

void			pixel_put(t_image *img, int x, int y, unsigned int color)
{
	ft_memcpy(img->data_addr + (img->pixels_per_line * y + x) *
			img->chars_per_pixel, (const void *)(&color), img->chars_per_pixel);
}