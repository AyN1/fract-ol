/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:24:01 by atbicer           #+#    #+#             */
/*   Updated: 2024/09/15 21:10:07 by atbicer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	[0..799] -> [-2..+2]
*/

#include "fractol.h"

static double	scale(double unscaled_num, t_range old, t_range new)
{
	return ((unscaled_num - old.min) / (old.max - old.min));
}

static double	translate(double scaled_num, t_range new)
{
	return (scaled_num * (new.max - new.min) + new.min);
}

double	map(double unscaled_num, t_range old, t_range new)
{
	double	scaled;

	scaled = scale(unscaled_num, old, new);
	return (translate(scaled, new));
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/*
   Square
   real = (x^2 - y^2)
   i = 2*x*y
*/

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
