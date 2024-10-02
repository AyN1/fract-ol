/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:07:20 by atbicer           #+#    #+#             */
/*   Updated: 2024/09/22 14:20:45 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
//# include <X11/X.h>
//# include "minilibx-linux/mlx.h"
# include "/usr/local/include/mlx.h"

# define ERROR_MESSAGE "Usage: \t./fractol mandelbrot\n\t\
./fractol julia <value_1> <value_2>\n"

/*
	Square to keep rendering math simple
*/

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

// Psychedelic colors
# define NEON_PINK 0xFF6EC7     // Neon Pink
# define ELECTRIC_BLUE 0x7DF9FF // Bright Electric Blue
# define LIME_GREEN 0x32CD32    // Vivid Lime Green
# define VIVID_ORANGE 0xFF5F1F  // Bright Vivid Orange
# define HOT_PINK 0xFF69B4      // Hot Pink
# define LASER_YELLOW 0xFFFF66  // Laser Yellow
# define ACID_GREEN 0xB0BF1A    // Acid Green
# define ULTRA_VIOLET 0x5F00FF  // Ultra Violet
# define VIVID_AQUA 0x00FFCC    // Bright Aqua
# define RAINBOW 0xF013D1       // Rainbow Mix Vibe
# define NEON_PURPLE 0x9D00FF   // Neon Purple

// Keys
# define XK_LEFT 123
# define XK_RIGHT 124
# define XK_DOWN 125
# define XK_UP 126
# define XK_PLUS 24
# define XK_MINUS 27
# define XK_ESCAPE 53
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_BTN 3
# define MOUSE_BTN 1
# define MOUSE_BTN_2 2

/*
	COMPLEX Value x = real and y = i
*/
typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;

	// Hooks member variables // hypotenuse
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

typedef struct s_range
{
	double	min;
	double	max;
}			t_range;
/* String utils*/
double		atodbl(char *s);

/* Init*/
void		fractal_init(t_fractal *fractal);

/* render */
void		fractal_render(t_fractal *fractal);

/* Math */
double		map(double unscaled_num, t_range old, t_range new);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

/* Hooks events */
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);

/* Clean up */
int			close_handler(t_fractal *fractal);

int			julia_track(int x, int y, t_fractal *fractal);

#endif
