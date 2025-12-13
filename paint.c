/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:18:33 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/13 23:39:36 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_frac *frac, char *str) // image ı piksel piksel gezer
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (strncmp(str, "mandelbrot", 11) == 0)
				calculate_mandelbrot(frac, x, y);
			// if (strncmp(str, "julia", 6) == 0)
			// 	calculate_julia(&frac, frac->j_cx, frac->j_cy);
			x++;
		}
		y++;
	}
}
void	calculate_mandelbrot(t_frac *frac, int x, int y)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	int		i;
	double	zr2;
	double	zi2;
	double	real;
	double	imag;
    unsigned int color;
    char  *pix_address;

	real = frac->min_x + (double)x / WIDTH * (frac->max_x - frac->min_x);
	imag = frac->max_y - (double)y / HEIGHT * (frac->max_y - frac->min_y);
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
    if(i == frac->max_iter)
        color = 0x000000;
    else
        color = i * 0xFFC0CB;
    pix_address = frac->img_data
    + (y * (frac->size_line) + x * (frac->bits_per_pixel / 8));

    *(unsigned int *)pix_address = color;
   
}
void	calculate_julia(t_frac *frac, double cx, double cy)
{
	double zr = real;
	double zi = imag;

	double cr = frac->j_cx;
	double ci = frac->j_cy;

	int i = 0;

	while (i < frac->max_iter)
	{
		double zr2 = zr * zr - zi * zi + cr;
		double zi2 = 2 * zr * zi + ci;

		zr = zr2;
		zi = zi2;

		if (zr * zr + zi * zi > 4.0)
			break ;

		i++;
	}
}