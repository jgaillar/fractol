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

int		mouse_hook(int x, int y, t_stuff *stuff)
{
	if (stuff->type == 2 && x <= WIDTH && y <= WIDTH && x >= 0 && y >= 0 &&\
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
	if (button == 4)
		plus(stuff, x, y);
	if (button == 5)
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
	stuff->frc.x1 += ((double)x - ((double)x / WIDTH * \
	(WIDTH * stuff->frc.zoom))) / 10000;
	stuff->frc.x2 -= (((double)WIDTH - x) - ((double)WIDTH - x) / WIDTH * \
	(WIDTH * stuff->frc.zoom)) / 10000;
	stuff->frc.y1 += ((double)y - ((double)y / LENGTH * \
	(LENGTH * stuff->frc.zoom))) / 10000;
	stuff->frc.y2 -= (((double)LENGTH - y) - ((double)LENGTH - y) / \
	LENGTH * (LENGTH * stuff->frc.zoom)) / 10000;
	if (stuff->frc.zoom + 0.01385 <= 1)
		stuff->frc.zoom += 0.01385;
}

void	minus(t_stuff *stuff, int x, int y)
{
	stuff->frc.x1 -= ((double)x - ((double)x / WIDTH * \
	(WIDTH * stuff->frc.zoom))) / 10000;
	stuff->frc.x2 += (((double)WIDTH - x) - ((double)WIDTH - x) / \
	WIDTH * (WIDTH * stuff->frc.zoom)) / 10000;
	stuff->frc.y1 -= ((double)y - ((double)y / LENGTH * \
	(LENGTH * stuff->frc.zoom))) / 10000;
	stuff->frc.y2 += (((double)LENGTH - y) - \
	((double)LENGTH - y) / LENGTH * (LENGTH * stuff->frc.zoom)) / 10000;
	if (stuff->frc.zoom - 0.0138 >= 0)
		stuff->frc.zoom -= 0.0138;
}
