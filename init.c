/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:45:46 by atbicer           #+#    #+#             */
/*   Updated: 2024/09/22 13:24:17 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* fractal init.
	INIT mlx
	listening events
	hooks data
*/

static void	malloc_error(void)
{
	perror("Problems with maloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}
/* KeyPress, KeyPressMask | ButtonPress, ButtonPressMask | DestroyNotify,
	StructureNotifyMask | MotionNotify, PointerMotionMask*/

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
		02,
		(1L << 0),
		key_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		04,
		(1L << 2),
		mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		17,
		(1L << 17),
		close_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		06,
		(1L << 6),
		julia_track,
		fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_window)
	{
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
