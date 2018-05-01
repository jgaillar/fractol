/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 02:18:46 by jgaillar          #+#    #+#             */
/*   Updated: 2017/08/03 13:50:38 by jgaillar         ###   ########.fr       */
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
	else if (stuff->type == 3)
		burningship(stuff);
	return (0);
}

void	echap(int keycode, t_stuff *stuff)
{
	if (keycode == 53)
	{
		stuff->exit = 2;
		exit(0);
	}
	if (keycode == 15)
		init_struct(stuff);
	if (keycode == 37)
	{
		if (stuff->frc.lock == 0)
			stuff->frc.lock = 1;
		else
			stuff->frc.lock = 0;
	}
}

void	hormovement(int keycode, t_stuff *stuff)
{
	if (keycode == 123)
	{
		stuff->frc.x1 -= (0.05 / stuff->frc.zoom) / 100;
		stuff->frc.x2 -= (0.05 / stuff->frc.zoom) / 100;
	}
	if (keycode == 124)
	{
		stuff->frc.x1 += (0.05 / stuff->frc.zoom) / 100;
		stuff->frc.x2 += (0.05 / stuff->frc.zoom) / 100;
	}
}

void	vermovement(int keycode, t_stuff *stuff)
{
	if (keycode == 126)
	{
		stuff->frc.y1 -= (0.05 / stuff->frc.zoom) / 100;
		stuff->frc.y2 -= (0.05 / stuff->frc.zoom) / 100;
	}
	if (keycode == 125)
	{
		stuff->frc.y1 += (0.05 / stuff->frc.zoom) / 100;
		stuff->frc.y2 += (0.05 / stuff->frc.zoom) / 100;
	}
}

void	itehook(int keycode, t_stuff *stuff)
{
	if (keycode == 24)
	{
		if (!(stuff->frc.max_it + 1 > IT))
			stuff->frc.max_it += 1;
	}
	if (keycode == 27)
	{
		if (!(stuff->frc.max_it - 1 < 0))
			stuff->frc.max_it -= 1;
	}
}
