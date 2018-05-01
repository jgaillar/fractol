/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:17:03 by jgaillar          #+#    #+#             */
/*   Updated: 2017/06/20 00:15:03 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

void			ft_exit(int code)
{
	ft_putstr("Error happened: ");
	ft_putnbr(code);
	ft_putendl("\nExiting.");
	exit(code);
}

static void		ft_usage(void)
{
	ft_putendl("Usage: ./fractol <mandelbrot /julia / burningship>");
	ft_exit(0);
}

static void		check_type(char *s, t_stuff *stuff)
{
	if (ft_strcmp(s, "mandelbrot") == 0)
	{
		stuff->type = 1;
		init_struct(stuff);
		mandelbrot(stuff);
	}
	else if (ft_strcmp(s, "julia") == 0)
	{
		stuff->type = 2;
		init_struct(stuff);
		julia(stuff);
	}
	else if (ft_strcmp(s, "burningship") == 0)
	{
		stuff->type = 3;
		init_struct(stuff);
		burningship(stuff);
	}
	else
		ft_usage();
}

int				main(int ac, char **av)
{
	t_stuff stuff;

	if (ac != 2 || !av[1])
		ft_usage();
	stuff.img.mlx_ptr = mlx_init();
	stuff.img.win_ptr = mlx_new_window(stuff.img.mlx_ptr, WIDTH, LENGTH,\
			"FRACTOL");
	check_type(av[1], &stuff);
	controlhelp();
	mlx_hook(stuff.img.win_ptr, 2, (1L << 0), hooks, &stuff);
	mlx_hook(stuff.img.win_ptr, 6, (1L << 6), mouse_hook, &stuff);
	mlx_hook(stuff.img.win_ptr, 4, (1L << 2), zoom, &stuff);
	mlx_loop(stuff.img.mlx_ptr);
	return (0);
}
