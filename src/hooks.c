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
	if (stuff->type == 2 && x <= WIDTH && y <= WIDTH && x >= 0 && y >= 0)
	{
		stuff->frc.c_r = ((x * stuff->frc.c_r) / stuff->frc.c_r) / 1000;
		stuff->frc.c_i = ((y * stuff->frc.c_i) / stuff->frc.c_i) / 10000;
		julia(stuff);
	}
	return (0);
}

int		zoom(int button, int x, int y, t_stuff *stuff)
{
	if (button == 1)
	{
		checkx(stuff, x);
		//checky(stuff, y);
	}
	if (button == 5)
	{
		stuff->frc.x1 += 0.01;
		stuff->frc.x2 -= 0.01;
		stuff->frc.y1 += 0.01;
		stuff->frc.y2 -= 0.01;
	}
	if (button == 4)
	{
		stuff->frc.x1 -= 0.01;
		stuff->frc.x2 += 0.01;
		stuff->frc.y1 -= 0.01;
		stuff->frc.y2 += 0.01;
	}
	if (stuff->type == 1)
		mandelbrot(stuff);
	else if (stuff->type == 2)
		julia(stuff);

	return (0);
}

void		checkx(t_stuff *stuff, int x)
{
	double tmp = 0;
	double tmp1 = 0;
	double tmp2 = 0;

	if (x < WIDTH/2)
	{
		tmp = (WIDTH/2) - x;
		tmp1 = (tmp * 100) / WIDTH;
		tmp2 = (tmp1 * (stuff->frc.x2)) / 100;
		//printf("%f\n", tmp2);
		stuff->frc.x1 -= tmp2;
		stuff->frc.x2 -= tmp2;
	}
	else if (x > WIDTH/2)
	{
		tmp = WIDTH - x;
		tmp1 = (tmp * 100) / WIDTH;
		tmp2 = (tmp1 * (stuff->frc.x2)) / 100;
		//printf("%f\n", tmp2);
		stuff->frc.x1 += tmp2;
		stuff->frc.x2 += tmp2;
	}
	printf("%f\n", stuff->frc.x1);
	printf("%f\n", stuff->frc.x2);
}

void		checky(t_stuff *stuff, int y)
{
	double tmp = 0;
	double tmp1 = 0;
	double tmp2 = 0;

	if (y < LENGTH/2)
	{
		tmp = (LENGTH/2) - y;
		tmp1 = (tmp * 100) / LENGTH;
		tmp2 = (tmp1 * (stuff->frc.y1)) / 100;
		stuff->frc.y1 += tmp2;
		stuff->frc.y2 += tmp2;
	}
	else if (y > LENGTH/2)
	{
		tmp = LENGTH - y;
		tmp1 = (tmp * 100) / LENGTH;
		tmp2 = (tmp1 * (stuff->frc.y1)) / 100;
		stuff->frc.y1 -= tmp2;
		stuff->frc.y2 -= tmp2;
	}
}
