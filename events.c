/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:36:36 by atbicer           #+#    #+#             */
/*   Updated: 2024/09/22 13:23:38 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 53)
		close_handler(fractal);
	else if (keysym == XK_LEFT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_RIGHT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_UP)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_DOWN)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_PLUS)
		fractal->iterations_definition += 10;
	else if (keysym == XK_MINUS)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

/* int (*f)(int button, int x, int y, void *param) */

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == MOUSE_WHEEL_DOWN)
	{
		fractal->zoom *= 1.05;
	}
	else if (button == MOUSE_WHEEL_UP)
	{
		fractal->zoom *= 0.95;
	}
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 6))
	{
		fractal->julia_x = (map(x, (t_range){0, WIDTH - 1}, (t_range){-2, 2})
				* fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map(y, (t_range){0, HEIGHT - 1}, (t_range){+2, -2})
				* fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
