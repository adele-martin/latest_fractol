#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_complex
{
	//real n
	double x;
	//imaginary n
	double y;

} t_complex;

typedef struct	s_image
{
	void	*img_ptr;
	char	*pixel;
	int		bpp;
	int		size_line;
	int		endian;
	char *addr;
}	t_image;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win;
	t_image	image;
	char	*name;
	double param_x;
	double param_y;
	int color;
	double	x_max;
	double offset_y;
	double offset_x;
	double move_x;
	double move_y;
	double	x_min;
	double	y_max;
	double	y_min;
	double zoom;
	int		iter;
	int		max_iter;
} t_fractal;

//Window dimensions
# define WIDTH	800
# define HEIGHT	800

// Keys
# define KEY_ESC 65307
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

//Mouse wheel
# define MOUSE_UP 4
# define MOUSE_DOWN 5

//Handle arguments
int handle_arguments(t_fractal *fractal, char **argv, int argc);
void get_julia_values(t_fractal *fractal, char **argv, int argc);

//Utils
double ft_atof(const char *str);

//Initialization
void init_values(t_fractal *fractal);
int fractal_init(t_fractal *fractal);

//Render fractol
void my_mlx_pixel_put(int x, int y, t_fractal *fractal, int color);
void render_fractal(t_fractal *fractal);
void mandelbrot(t_complex *comp, t_fractal *fractal);
void julia(t_complex *comp, t_fractal *fractal);
void mandel_vs_julia(t_complex *comp, t_fractal *fractal);

//Handle events
int handle_keys(int key, t_fractal *fractal);
int handle_mouse(int button, int x, int y, t_fractal *fractal);

//Clean and exit
int kill_window(t_fractal *fractal);
int exit_clean(t_fractal *fractal);

//Coloring functions
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
// int get_color(int iter);
int get_color(int iter, int max_iter);

#endif
