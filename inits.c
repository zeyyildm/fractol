/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 02:14:28 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/06 03:32:48 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	after_point(const char *nptr)
{
	double	multiple;
	double	result;
	
	result = 0.0;
	multiple = 10;
	if (*nptr == '.')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result +=  (*nptr - 48) / multiple;
		multiple *= 10;
		nptr++;
	}
	return (result);
}

double	ft_atof(const char *nptr)
{
	double	sign;
	double	result;
    double  point_part;

	sign = 1.0;
	result = 0.0;
    point_part = 0.0;
    
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1.0;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	result += after_point(nptr);
	return (result * sign);
}

void init_julia(t_frac *f, double cx, double cy)
{
    f->min_x = -2.0;
    f->max_x = 2.0;
    f->min_y = -2.0;
    f->max_y = 2.0;
    f->zoom = 1.0;
    f->j_cx = cx;
    f->j_cy = cy; 
}

void init_mandelbrot(t_frac *f)
{
    f->min_x = -2.0;
    f->max_x = 1.0;
    f->min_y = -1.5;
    f-> max_y = 1.5;
    f-> zoom = 1.0;
    f->max_iter = 50;
    f->j_cx = 0;
    f->j_cy = 0;
}