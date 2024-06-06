#include "fractol.h"

int handle_keys(int key, t_fractal *fractal)
{
	if (key == KEY_ESC)
	{
		kill_window(fractal);
	}
	if (key == KEY_LEFT) //right arrow --> zoom in
		fractal->move_x += (0.5 * fractal->zoom);
	else if (key == KEY_RIGHT) //left arrow
		fractal->move_x -= (0.5 * fractal->zoom);
    //else if (key )
	render_fractal(fractal);
	return (0);
}

/*
int handle_mouse(int button, int x, int y, t_fractal *fractal)
{
    if (key == KEY_RIGHT) //right arrow --> zoom in
		fractal->zoom *= 0.5;
	else if (key == KEY_LEFT) //left arrow
		fractal->zoom *= 2.0;
	render_fractal(fractal);
    return (0);
}
*/