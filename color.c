#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_red(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_green(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_blue(int trgb)
{
	return ((trgb & 0xFF));
}

int get_color(int iter)
{
	int color_intensity = iter * 25;
    int blue = color_intensity % 256; // Ensures red stays within the 0-255 range
    int white_blend = (color_intensity / 2) % 256; // Blend white with red
    int green = (color_intensity / 3) % 256; // Reduces green intensity
    //int red = (color_intensity / 4) % 256; // Reduces blue intensity even more
	int red = (color_intensity / 8) % 256;
	//int red = (color_intensity / 6) % 256;
	//int red = (color_intensity / 2) % 256;
    // Blend white with red component
    blue = (blue + white_blend) / 2;
	return create_trgb(0, red, green, blue);
	//return (create_trgb(0, get_red(color), get_green(color), get_blue(color)));
}