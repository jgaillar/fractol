/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 02:26:31 by jgaillar          #+#    #+#             */
/*   Updated: 2017/06/24 02:27:02 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		hooks(int keycode, t_stuff *stuff)
{
	echap(keycode, stuff);
	hormovement(keycode, stuff);
	vermovement(keycode, stuff);
	itehook(keycode, stuff);
	if (stuff->type == 1)
		mandelbrot(stuff);
	else if (stuff->type == 2)
		julia(stuff);
	return (0);
}

int		mouse_hook(int x, int y, t_stuff *stuff)
{
	if (stuff->type == 2 && x <= WIDTH && y <= WIDTH && x >= 0 && y >= 0)
	{

		stuff->frc.c_r = (stuff->frc.c_r / x) * (stuff->frc.c_i / y);
		stuff->frc.c_i = (stuff->frc.c_i / y) * (stuff->frc.c_r / x);
		ft_putnbr(stuff->frc.c_r);
		ft_putchar('\n');
		ft_putnbr(stuff->frc.c_i);
		ft_putchar('\n');
		julia(stuff);
	}
	return (0);
}
