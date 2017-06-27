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

void				refresh(t_stuff *stuff)
{
	mlx_destroy_image(stuff->img.mlx_ptr, stuff->img.img_ptr);
	stuff->img.img_ptr = mlx_new_image(stuff->img.mlx_ptr, WIDTH, LENGTH);
	stuff->img.data = mlx_get_data_addr(stuff->img.img_ptr, \
		&stuff->img.bits_per_pixel, &stuff->img.size_line, &stuff->img.endian);
	if (stuff->type == 1)
		mandelbrot(stuff);
	else if (stuff->type == 2)
		julia(stuff);
	mlx_put_image_to_window(stuff->img.mlx_ptr, stuff->img.win_ptr, \
		stuff->img.img_ptr, 0, 0);
}

void			julia(t_stuff *stuff)
{
	double tmp;

	stuff->frc.y = -1;

	while (++stuff->frc.y < LENGTH)
	{
		stuff->frc.x = -1;
		while (++stuff->frc.x < WIDTH)
		{
			stuff->frc.c_r = 0.285;
			stuff->frc.c_i = 0.01;
			stuff->frc.z_r = stuff->frc.x / stuff->frc.zoom + stuff->frc.x1;
			stuff->frc.z_i = stuff->frc.y / stuff->frc.zoom + stuff->frc.y1;
			stuff->frc.i = -1;
			while (stuff->frc.z_r * stuff->frc.z_r + stuff->frc.z_i * stuff->frc.z_i < 4 && ++stuff->frc.i < stuff->frc.MAX_IT)
			{
				tmp = stuff->frc.z_r;
				stuff->frc.z_r = ((stuff->frc.z_r * stuff->frc.z_r) - (stuff->frc.z_i * stuff->frc.z_i)) + stuff->frc.c_r;
				stuff->frc.z_i = 2 * stuff->frc.z_i * tmp + stuff->frc.c_i;
			}
			if (stuff->frc.i == stuff->frc.MAX_IT)
				mlx_pixel_put_to_image(stuff->img, stuff->frc.x, stuff->frc.y, 0x000000);
			else
				mlx_pixel_put_to_image(stuff->img, stuff->frc.x, stuff->frc.y, stuff->img.color[stuff->frc.i]);
		}
	}
}

void			mandelbrot(t_stuff *stuff)
{
	double tmp;

	stuff->frc.y = -1;

	while (++stuff->frc.y < LENGTH)
	{
		stuff->frc.x = -1;
		while (++stuff->frc.x < WIDTH)
		{
			stuff->frc.c_r = stuff->frc.x / stuff->frc.zoom + stuff->frc.x1;
			stuff->frc.c_i = stuff->frc.y / stuff->frc.zoom + stuff->frc.y1;
			stuff->frc.z_r = 0;
			stuff->frc.z_i = 0;
			stuff->frc.i = -1;
			while (stuff->frc.z_r * stuff->frc.z_r + stuff->frc.z_i * stuff->frc.z_i < 4 && ++stuff->frc.i < stuff->frc.MAX_IT)
			{
				tmp = stuff->frc.z_r;
				stuff->frc.z_r = ((stuff->frc.z_r * stuff->frc.z_r) - (stuff->frc.z_i * stuff->frc.z_i)) + stuff->frc.c_r;
				stuff->frc.z_i = 2 * stuff->frc.z_i * tmp + stuff->frc.c_i;
			}
			if (stuff->frc.i == stuff->frc.MAX_IT)
				mlx_pixel_put_to_image(stuff->img, stuff->frc.x, stuff->frc.y, 0x000000);
			else
				mlx_pixel_put_to_image(stuff->img, stuff->frc.x, stuff->frc.y, stuff->img.color[stuff->frc.i]);
		}
	}
}

void			ft_exit(int code)
{
	ft_putstr("Error happened: ");
	ft_putnbr(code);
	ft_putendl("\nExiting.");
	exit(code);
}

static void		ft_usage(void)
{
	ft_putendl("Usage: ./fractol <map>");
	ft_exit(0);
}

int				main(int ac, char **av)
{
	t_stuff stuff;

	if (ac != 2 || !av[1])
		ft_usage();
	stuff.img.mlx_ptr = mlx_init();
	stuff.img.win_ptr = mlx_new_window(stuff.img.mlx_ptr, WIDTH, LENGTH,\
			"FRACTOL");
	if (av[1][0] == 49)
	{
		init_struct(&stuff, 1);
		mandelbrot(&stuff);
	}
	else if (av[1][0] == 50)
	{
		init_struct(&stuff, 2);
		julia(&stuff);
	}
	else
		ft_usage();
	mlx_put_image_to_window(stuff.img.mlx_ptr, stuff.img.win_ptr, \
		stuff.img.img_ptr, 0, 0);
	mlx_hook(stuff.img.win_ptr, 2, (1l << 0), hooks, &stuff);
	mlx_loop(stuff.img.mlx_ptr);
	return (0);
}
