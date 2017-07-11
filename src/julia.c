/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 23:11:05 by jgaillar          #+#    #+#             */
/*   Updated: 2017/07/04 23:11:06 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void			julia(t_stuff *stuff)
{
	stuff->i = -1;

	while (++stuff->i < MT)
	{
		t_tmp *tmp;
		tmp = malloc(sizeof(t_tmp));
		tmp->start = stuff->i * WIDTH/MT;
		tmp->end = tmp->start + WIDTH/MT;
		tmp->stuff = stuff;
		pthread_create(&stuff->th[stuff->i], NULL, (void *(*)(void *))(&draw_julia), (void*)(tmp));
	}
	stuff->j = -1;
	while (++stuff->j < MT)
		pthread_join(stuff->th[stuff->j], NULL);
	mlx_put_image_to_window(stuff->img.mlx_ptr, stuff->img.win_ptr, \
		stuff->img.img_ptr, 0, 0);
}
//
// px: 200
// py: 100
//
// posFracX = (float)(px / WIDTH) * (x2 - x1)
// posFracY = (float)(py / HEIGHT) * (y2 - y1)

void			*draw_julia(t_tmp *tmp)
{
	double temp;

	t_stuff *stuff = tmp->stuff;
	t_frac frac;
	set_julia(tmp, &frac);
	while (++frac.x < frac.end)
	{
		frac.y = -1;
		while (++frac.y < LENGTH)
		{
			frac.c_r = stuff->frc.c_r;
			frac.c_i = stuff->frc.c_i;
			frac.z_r = (frac.x / WIDTH) * (frac.x2 - frac.x1) + frac.x1;
			frac.z_i = (frac.y / LENGTH) * (frac.y2 - frac.y1) + frac.y1;
			frac.i = -1;
			while (frac.z_r * frac.z_r + frac.z_i * frac.z_i < 4 && ++frac.i < stuff->frc.MAX_IT)
			{
				temp = frac.z_r;
				frac.z_r = ((frac.z_r * frac.z_r) - (frac.z_i * frac.z_i)) + frac.c_r;
				frac.z_i = 2 * frac.z_i * temp + frac.c_i;
			}
			if (frac.i == stuff->frc.MAX_IT)
				mlx_pixel_put_to_image(stuff->img, frac.x, frac.y, 0x000000);
			else
				mlx_pixel_put_to_image(stuff->img, frac.x, frac.y, stuff->img.color[frac.i]);
		}
	}
	free(tmp);
return (NULL);
}

void			set_julia(t_tmp *tmp, t_frac *frac)
{
	frac->x = tmp->start - 1;
	frac->end = tmp->end;
	frac->x1 = tmp->stuff->frc.x1;
	frac->x2 = tmp->stuff->frc.x2;
	frac->y1 = tmp->stuff->frc.y1;
	frac->y2 = tmp->stuff->frc.y2;
}
