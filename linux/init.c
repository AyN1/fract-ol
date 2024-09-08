/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:45:46 by atbicer           #+#    #+#             */
/*   Updated: 2024/09/08 12:19:39 by atbicer          ###   ########.fr       */
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

void		data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error(); // TODO
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, 
					WIDTH, 
					HEIGHT, 
					fractal->name);
	if (NULL == fractal->mlx_window)
	{
		// can't detroy display with macos minilibx... but possible with linux  one
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
						WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
							&fractal->img.bpp,
							&fractal->img.line_len,
							&fractal->img.endian);
	// events_init(fractal); // todo
	data_init(fractal); //todo
}
