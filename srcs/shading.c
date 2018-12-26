unsigned int	lerp_color(unsigned int color, double ratio)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = (color & 0xFF0000) >> 16;
	green = (color & 0xFF00) >> 8;
	blue = color & 0xFF;
	red = (int)(ratio * red);
	green = (int)(ratio * green);
	blue = (int)(ratio * blue);
	return ((unsigned int)(red << 16 | green << 8 | blue));
}