/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:18:33 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/14 02:55:18 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_frac *frac, char *str)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (ft_strncmp(str, "mandelbrot", 11) == 0)
				calculate_mandelbrot(frac, x, y);
			if (ft_strncmp(str, "julia", 6) == 0)
				calculate_julia(frac, x, y);
			x++;
		}
		y++;
	}
}

void	calculate_mandelbrot(t_frac *frac, int x, int y)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	real_and_imag(frac, x, y);
	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < frac->max_iter)
	{
		tmp = zr * zr - zi * zi + frac->real;
		zi = 2 * zr * zi + frac->imag;
		zr = tmp;
		if (zr * zr + zi * zi > 4.0)
			break ;
		i++;
	}
	pix_address(frac, x, y, i);
}

void	calculate_julia(t_frac *frac, int x, int y)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	real_and_imag(frac, x, y);
	zr = frac->real;
	zi = frac->imag;
	i = 0;
	while (i < frac->max_iter)
	{
		tmp = zr * zr - zi * zi + frac->j_cx;
		zi = 2 * zr * zi + frac->j_cy;
		zr = tmp;
		if (zr * zr + zi * zi > 4.0)
			break ;
		i++;
	}
	pix_address(frac, x, y, i);
}

void	pix_address(t_frac *frac, int x, int y, int i)
{
	char			*pix_address;
	unsigned int	color;

	if (i == frac->max_iter)
		color = 0x000000;
	else
		color = i * 0xFFC0CB;
	pix_address = frac->img_data + (y * (frac->size_line) + x
			* (frac->bits_per_pixel / 8));
	*(unsigned int *)pix_address = color;
}

void	real_and_imag(t_frac *frac, int x, int y)
{
    double center_x = (frac->min_x + frac->max_x) / 2;
    double center_y = (frac->max_y + frac->min_y) / 2;
	frac->real = center_x
		+ ((double)x - WIDTH / 2)
		/ (WIDTH / 2)
		* ((frac->max_x - frac->min_x) / frac->zoom);

	frac->imag = center_y
		- ((double)y - HEIGHT / 2)
		/ (HEIGHT / 2)
		* ((frac->max_y - frac->min_y) / frac->zoom);
}
