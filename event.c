/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:41:43 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/14 03:20:50 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_events(int code, void *a)
{
	if (code == 65307)
		destroy_everything(a);
	return (0);
}

int	zoom_in(int button, int x, int y, void *param)
{
	t_frac	*frac;
	double	zoom_x;

	frac = (t_frac *)param;
	(void)x;
	(void)y;
	zoom_x = 1.1;
	if (button == 4)
		frac->zoom *= zoom_x;
	if (button == 5)
		frac->zoom /= zoom_x;
	if (strcmp(frac->title, "mandelbrot") == 0)
		render(frac, "mandelbrot");
	else if (strcmp(frac->title, "julia") == 0)
		render(frac, "julia");
	mlx_put_image_to_window(frac->mlx_ptr, frac->mlx_win, frac->img_ptr, 0, 0);
	return (0);
}
