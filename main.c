/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:29:28 by atbicer           #+#    #+#             */
/*   Updated: 2024/09/22 14:27:28 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ./fractol mandelbrot
 ./fractol julia <real> <i>
*/

#include "fractol.h"

int	argument_error(int ac, char **av)
{
	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 11)
		|| 4 == ac && !ft_strncmp(av[1], "julia", 6))
		return (0);
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (1);
	}
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (!argument_error(ac, av))
	{
		fractal.name = av[1];
		if (!ft_strncmp(av[1], "julia", 6))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		exit(EXIT_FAILURE);
}
