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
#include <stdio.h>

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
	if (button == 5)
		checkx(stuff, x, y);
	if (stuff->type == 1)
		mandelbrot(stuff);
	else if (stuff->type == 2)
		julia(stuff);

	return (0);
}

void		checkx(t_stuff *stuff, int x, int y)
{
	if (stuff->frc.x1 + (((double)x - ((double)x/ WIDTH * \
	(WIDTH * stuff->frc.zoom))) / 10000) < 0 && stuff->frc.x2 - (((WIDTH - x) - \
	(WIDTH - x) / WIDTH * (WIDTH * stuff->frc.zoom)) / 10000) > 0 && \
stuff->frc.y1 + (((double)y - ((double)y/ LENGTH * (LENGTH * stuff->frc.zoom))) \
/ 10000) < 0 && stuff->frc.y2 - (((LENGTH - y) - (LENGTH - y) / \
LENGTH * (LENGTH * stuff->frc.zoom)) / 10000) > 0)
{
	stuff->frc.x1 += ((double)x - ((double)x/ WIDTH * (WIDTH * stuff->frc.zoom))) / 10000;
	stuff->frc.x2 -= (((double)WIDTH - x) - ((double)WIDTH - x) / WIDTH * (WIDTH * stuff->frc.zoom)) / 10000;
	stuff->frc.y1 += ((double)y - ((double)y/ LENGTH * (LENGTH * stuff->frc.zoom))) / 10000;
	stuff->frc.y2 -= (((double)LENGTH - y) - ((double)LENGTH - y) / LENGTH * (LENGTH * stuff->frc.zoom)) / 10000;
	if (stuff->frc.zoom + 0.015 < 1)
		stuff->frc.zoom += 0.015;
}
}
