/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:13:47 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/08 21:45:47 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGHT 1000
# define WIDTH  1000

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_frac
{
	char	*mlx_ptr;
    char    *mlx_win;
    double  min_x;
    double  max_x;
    double  min_y;
    double  max_y;
    double  j_cx;
    double  j_cy;
    double  zoom;
    int     max_iter;
    char    *title;
    void    *image;
}			t_frac;

typedef struct s_image
{
    char *img_ptr;
    char    *data;
} t_img;

void correct_usage(void);
void init_mandelbrot(t_frac *f);
void init_julia(t_frac *f, double cx, double cy);
double	ft_atof(const char *nptr);
double	after_point(const char *nptr);
int	arguments_parse(t_frac *f, int ac, char **av);
int	key_events(int code, void *a)


#endif