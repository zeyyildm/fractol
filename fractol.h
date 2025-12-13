/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:13:47 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/13 23:30:48 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGHT 800
# define WIDTH 1000

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_frac
{
	char	*mlx_ptr;
	char	*mlx_win;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	j_cx;
	double	j_cy;
	double	zoom;
	int		max_iter;
	char	*title;
	void	*image;
	char	*img_ptr;
	char	*img_data;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}			t_frac;

void		correct_usage(void);
void		init_mandelbrot(t_frac *f);
void		init_julia(t_frac *f, double cx, double cy);
double		ft_atof(const char *nptr);
double		after_point(const char *nptr);
int			arguments_parse(t_frac *f, int ac, char **av);
int			key_events(int code, void *a);
int			destroy_everything(void *a);
void		render(t_frac *frac, char *str);
void		calculate_mandelbrot(t_frac *frac, int x, int y);

#endif