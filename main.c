/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:13:49 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/08 21:57:07 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	correct_usage(void)
{
	write(1, "Usage: ", 8);
	write(1, "/fractol mandelbrot\n./fractol julia <real> <imaginary>\n", 56);
}

int	arguments_parse(t_frac *f, int ac, char **av)
{
	double	cx;
	double	cy;

	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])) == 0)
	{
		f->title = "mandelbrot";
		init_mandelbrot(f);
		return (1);
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", ft_strlen(av[1])) == 0)
	{
		cx = ft_atof(av[2]);
		cy = ft_atof(av[3]);
		if (!cx || !cy)
			return (0);
		f->title = "julia";
		init_julia(f, cx, cy);
		return (1);
	}
	else
		return (0);
}

void	mlx_inits_and_win(t_frac *f)
{
	f->mlx_ptr = mlx_init();
	f->mlx_win = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, f->title);
	f->image = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
}

void	paint_pixels(t_img *img, int x, int y)
{
	int				pixel_bits;
	int				line_bytes;
	int				endian;
	char			*pixel_adress;
	unsigned int	color;

	img->data = mlx_get_data_addr(img->img_ptr, &pixel_bits,
			&line_bytes, &endian);
	pixel_adress = img->data + (y * line_bytes + x * (pixel_bits / 8));
	color = 0xCBC0FF;
	*(unsigned int *)pixel_adress = color;
}

int	destroy_everything(void *a)
{
	t_frac	*frac;

	frac = (t_frac *)a;
	mlx_destroy_image(frac->mlx_ptr, frac->image);
	mlx_destroy_window(frac->mlx_ptr, frac->mlx_win);
	mlx_destroy_display(frac->mlx_ptr);
	free(frac->mlx_ptr);
	exit(1);
}

int	main(int ac, char **av)
{
	t_frac	frac;
	t_img	img;

	if (!arguments_parse(&frac, ac, av))
	{
		correct_usage();
		return (0);
	}
	mlx_inits_and_win(&frac);
	mlx_hook(frac.mlx_win, 17, 1L << 0, destroy_everything, (void *)&frac);
	mlx_hook(frac.mlx_win, 2, 1L << 0, key_events, (void *)&frac);
	paint_pixels(&img, 10, 10);
	int i;
	i = 1;
	while (i < 1000)
	{
		paint_pixels(&img, 10, i);
		i++;
	}
	mlx_put_image_to_window(frac.mlx_ptr, frac.mlx_win, img.img_ptr, 10, 10);
	mlx_loop(frac.mlx_ptr);
	return (0);
}
