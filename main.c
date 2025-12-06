/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:13:49 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/06 05:44:44 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void correct_usage(void)
{
    write(1, "Usage:\n./fractol mandelbrot\n./fractol julia <real> <imaginary>",63);
}

void arguments_parse(t_frac *f, int ac, char **av)
{
    if(ac < 2)
        correct_usage();
    if(strcmp(av[1], "mandelbrot") == 0)
    {
        f->title="mandelbrot";
        init_mandelbrot(f);
    }
    else if(strcmp(av[1], "julia") == 0)
    {
        double cx;
        double cy;

        cx = ft_atof(av[2]);
        cy = ft_atof(av[3]);
        f->title="mandelbrot";
        init_julia(f, cx, cy);
    }
    else
        correct_usage();  
}
void mlx_inits_and_win(t_frac *f)
{
    f->mlx_ptr= mlx_init();
    f->mlx_win=mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, f->title); 
    f->image = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
}


int destroy_everything(void *a)
{
    t_frac *frac = (t_frac *)a;
    mlx_destroy_image(frac->mlx_ptr, frac->image);
    mlx_destroy_window(frac->mlx_ptr, frac->mlx_win);
    mlx_destroy_display(frac->mlx_ptr);
    free(frac->mlx_ptr);
    exit(1);
    
}

int key_events(int code, void *a)
{
    //t_frac *frac = (t_frac *)a;
    if( code == 65307)
        destroy_everything(a);
    exit(1);
    
}
int main(int ac, char **av)
{
    t_frac frac;
    arguments_parse(&frac, ac, av);
    mlx_inits_and_win(&frac);
    mlx_hook(frac.mlx_win, 17, 1L<<0, destroy_everything,  (void *)&frac);
    mlx_hook(frac.mlx_win, 2, 1L<<0, key_events,  (void *)&frac);
    mlx_loop(frac.mlx_ptr);
    return (0);

}