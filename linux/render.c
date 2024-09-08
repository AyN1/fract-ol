/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:04:53 by atbicer           #+#    #+#             */
/*   Updated: 2024/09/08 22:11:27 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	z = z^2 + c
	z initially is (0, 0)
	c is the actual point
*/

/*
   * Put a pixel in my image buffer
*/

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp /8));
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int		i;
	int		color;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;

	c.x = map(x, -2, 2, 0, WIDTH);
	c.y = map(y, 2, -2, 0, HEIGHT);

	// how many times you want to iterate z^2 + c
	// to check if the point escaped?
	while (i < fractal->iterations_definition)
	{
		// actual z^2 + c
		// z = z^2 + c
		z = sum_complex(square_complex(z), c);
		
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_definition); 
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, ACID_GREEN);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while(++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, 
				fractal->mlx_window,
				fractal->img.img_ptr,
				0, 0);
}
