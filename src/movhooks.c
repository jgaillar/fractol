/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 02:18:46 by jgaillar          #+#    #+#             */
/*   Updated: 2017/06/24 02:48:10 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		echap(int keycode, t_stuff *stuff)
{
	if (keycode == 53)
	{
		ft_strdel(&stuff->img.data);
		exit (0);
	}
}

void		hormovement(int keycode, t_stuff *stuff)
{
	if (keycode == 123)
	{
		stuff->frc.x1 -= 0.05;
		stuff->frc.x2 -= 0.05;
	}
	if (keycode == 124)
	{
		stuff->frc.x1 += 0.05;
		stuff->frc.x2 += 0.05;
	}
}

void		vermovement(int keycode, t_stuff *stuff)
{
	if (keycode == 126)
	{
		stuff->frc.y1 -= 0.05;
		stuff->frc.y2 -= 0.05;
	}
	if (keycode == 125)
	{
		stuff->frc.y1 += 0.05;
		stuff->frc.y2 += 0.05;
	}
}

void		itehook(int keycode, t_stuff *stuff)
{
	if (keycode == 24)
	{
		if (!(stuff->frc.MAX_IT + 1 > 50))
			stuff->frc.MAX_IT += 1;
	}
	if (keycode == 27)
	{
		if (!(stuff->frc.MAX_IT - 1 < 0))
			stuff->frc.MAX_IT -= 1;
	}
	if (keycode == 69)
		stuff->frc.zoom += stuff->frc.zoom/10;
	if (keycode == 78)
		stuff->frc.zoom -= stuff->frc.zoom/10;
}
