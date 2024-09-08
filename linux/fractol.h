/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:07:20 by atbicer           #+#    #+#             */
/*   Updated: 2024/09/08 22:05:46 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <stdio.h> // TODO debug
# include <stdlib.h> // malloc free
# include <unistd.h> // write
# include <math.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Usage: \t./fractol mandelbrot\n\t./fractol julia <value_1> <value_2>\n"

/*
	Square to keep rendering math simple
*/

# define WIDTH	800
# define HEIGHT	800

#define BLACK	0x000000
#define WHITE	0xFFFFFF
#define RED	0xFF0000
#define GREEN	0x00FF00
#define BLUE	0x0000FF
#define YELLOW	0xFFFF00
#define CYAN	0x00FFFF
#define MAGENTA	0xFF00FF
#define ORANGE	0xFFA500
#define PURPLE	0x800080
#define GRAY	0x808080

// Psychedelic colors
#define NEON_PINK	0xFF6EC7  // Neon Pink
#define ELECTRIC_BLUE	0x7DF9FF  // Bright Electric Blue
#define LIME_GREEN	0x32CD32  // Vivid Lime Green
#define VIVID_ORANGE	0xFF5F1F  // Bright Vivid Orange
#define HOT_PINK	0xFF69B4  // Hot Pink
#define LASER_YELLOW	0xFFFF66  // Laser Yellow
#define ACID_GREEN	0xB0BF1A  // Acid Green
#define ULTRA_VIOLET	0x5F00FF  // Ultra Violet
#define VIVID_AQUA	0x00FFCC  // Bright Aqua
#define RAINBOW		0xF013D1  // Rainbow Mix Vibe
#define NEON_PURPLE	0x9D00FF  // Neon Purple

/*
	COMPLEX Value
*/
typedef struct	s_complex
{
	double	x; // real
	double	y; //i
}		t_complex;

typedef struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; // points to the actuals pixels
	int	bpp;
	int	endian;
	int	line_len;
}		t_img;

typedef struct	s_fractal
{
	char	*name;
	// MLX
	void	*mlx_connection; 	// mlx_init();
	void	*mlx_window;		// mlx_new_window();
	// Image
	t_img	img;

	// Hooks member variables // TODO
	double	escape_value; // hypotenuse
	int	iterations_definition;
}		t_fractal;

/* Init*/
void		fractal_init(t_fractal *fractal);

/* render */
void	fractal_render(t_fractal *fractal);


/* Math */
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max); 
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif
