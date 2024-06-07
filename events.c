#include "fractol.h"

int handle_keys(int key, t_fractal *fractal)
{
	if (key == KEY_ESC)
	{
		kill_window(fractal);
	}
	if (key == KEY_LEFT)
		fractal->move_x += (0.5 * fractal->zoom);
	else if (key == KEY_RIGHT)
		fractal->move_x -= (0.5 * fractal->zoom);
	else if (key== KEY_UPWARDS)
		fractal->move_y += 0.05 * fractal->zoom;
	else if (key == KEY_DOWNWARDS)
		fractal->move_y -= 0.05 * fractal->zoom;
	render_fractal(fractal);
	return (0);
}

int handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	(void)y;
	(void)x;
    if (button == MOUSE_UP)
		fractal->zoom *= 0.5;
	else if (button == MOUSE_DOWN)
		fractal->zoom *= 2.0;
	render_fractal(fractal);
    return (0);
}
