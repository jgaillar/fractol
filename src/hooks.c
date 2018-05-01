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

#include "fractol.h"
#include <stdio.h>

int		mouse_hook(int x, int y, t_stuff *stuff)
{
	if (stuff->type == 2 && x <= WIDTH && y <= WIDTH && x > 0 && y > 0 &&\
	stuff->frc.lock == 1)
	{
		stuff->frc.c_r = ((x * stuff->frc.c_r) / stuff->frc.c_r) / 1000;
		stuff->frc.c_i = ((y * stuff->frc.c_i) / stuff->frc.c_i) / 10000;
		julia(stuff);
	}
	return (0);
}

int		zoom(int button, int x, int y, t_stuff *stuff)
{
	if (button == 5)
		plus(stuff, x, y);
	if (button == 4)
		minus(stuff, x, y);
	if (stuff->type == 1)
		mandelbrot(stuff);
	else if (stuff->type == 2)
		julia(stuff);
	else if (stuff->type == 3)
		burningship(stuff);
	return (0);
}

void	plus(t_stuff *stuff, int x, int y)
{
	if (stuff->tmp < 253)
	{
		stuff->frc.x1 += ((double)x - ((double)x / WIDTH * \
			(WIDTH * stuff->frc.zoom))) / 10000;
		stuff->frc.x2 -= (((double)WIDTH - x) - ((double)WIDTH - x) / WIDTH * \
			(WIDTH * stuff->frc.zoom)) / 10000;
		stuff->frc.y1 += ((double)y - ((double)y / LENGTH * \
			(LENGTH * stuff->frc.zoom))) / 10000;
		stuff->frc.y2 -= (((double)LENGTH - y) - ((double)LENGTH - y) / \
			LENGTH * (LENGTH * stuff->frc.zoom)) / 10000;
		if (stuff->frc.zoom + 0.01383 <= 1)
			stuff->frc.zoom += 0.01383;
		else
			stuff->tmp++;
	}
}

void	minus(t_stuff *stuff, int x, int y)
{
	if (stuff->frc.zoom > 0.1)
	{
		stuff->frc.x1 -= ((double)x - ((double)x / WIDTH * \
			(WIDTH * stuff->frc.zoom))) / 10000;
		stuff->frc.x2 += (((double)WIDTH - x) - ((double)WIDTH - x) / \
			WIDTH * (WIDTH * stuff->frc.zoom)) / 10000;
		stuff->frc.y1 -= ((double)y - ((double)y / LENGTH * \
			(LENGTH * stuff->frc.zoom))) / 10000;
		stuff->frc.y2 += (((double)LENGTH - y) - \
			((double)LENGTH - y) / LENGTH * (LENGTH * stuff->frc.zoom)) / 10000;
		if (stuff->tmp == 0)
		{
			if (stuff->frc.zoom - 0.01383 >= 0.1)
				stuff->frc.zoom -= 0.01383;
			else
				stuff->frc.zoom = 0.1;
		}
		else if (stuff->tmp - 1 >= 0)
			stuff->tmp--;
	}
}
