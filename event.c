/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:41:43 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/14 03:01:55 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_events(int code, void *a)
{
	if (code == 65307)
		destroy_everything(a);
	exit(1);
}

int zoom_in(t_frac *frac, int key_press)
{
	double zoom_x;
	printf("zoom in \n");
	zoom_x = 1.3;
	if(key_press == 4)
		frac->zoom *= zoom_x;
		
	if(key_press == 5)
		frac->zoom /= zoom_x;
	return (0);
}
