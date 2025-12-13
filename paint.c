/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:18:33 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/13 22:05:28 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_frac *frac, char *str) // image ı piksel piksel gezer
{
	double x;
	double y;
    double real;
    double imag;

	x = 0;
	y = 0;
	// real imaginer hesapla
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			real = frac->min_x + (double)x / WIDTH * (frac->max_x
					- frac->min_x);

			imag = frac->max_y - (double)y / HEIGHT * (frac->max_y
					- frac->min_y);

			if (strncmp(str, "mandelbrot", 11) == 0)
				calculate_mandelbrot(frac, real, imag);
			// if (strncmp(str, "julia", 6) == 0)
			// 	calculate_julia(&frac, frac->j_cx, frac->j_cy);
			x++;
		}
		y++;
	}
	// pixel_adress = img->data + (y * line_bytes + x * (pixel_bits / 8));
}
void	calculate_mandelbrot(t_frac *frac, double real, double imag)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	int		i;
	double	zr2;
	double	zi2;

	zr = 0.0;
	zi = 0.0;
	cr = real;
	ci = imag;
	i = 0;
	while (i < frac->max_iter)
	{
		zr2 = zr * zr - zi * zi + cr;
		zi2 = 2 * zr * zi + ci;
		zr = zr2;
		zi = zi2;
		if (zr * zr + zi * zi > 4.0)
			break ;
		i++;
	}
}
// void	calculate_julia(t_frac *frac, double cx, double cy)
// {
// 	double zr = real;
// 	double zi = imag;

// 	double cr = frac->j_cx;
// 	double ci = frac->j_cy;

// 	int i = 0;

// 	while (i < frac->max_iter)
// 	{
// 		double zr2 = zr * zr - zi * zi + cr;
// 		double zi2 = 2 * zr * zi + ci;

// 		zr = zr2;
// 		zi = zi2;

// 		if (zr * zr + zi * zi > 4.0)
// 			break ;

// 		i++;
// 	}
// }