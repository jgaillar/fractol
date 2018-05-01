/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 11:23:18 by jgaillar          #+#    #+#             */
/*   Updated: 2017/08/03 11:23:19 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		burningship(t_stuff *stuff)
{
	t_tmp *tmp;

	stuff->i = -1;
	while (++stuff->i < MT)
	{
		tmp = malloc(sizeof(t_tmp));
		tmp->start = stuff->i * WIDTH / MT;
		tmp->end = tmp->start + WIDTH / MT;
		tmp->stuff = stuff;
		pthread_create(&stuff->th[stuff->i], NULL, \
			(void *(*)(void *))(&draw_burningship), (void*)(tmp));
	}
	stuff->j = -1;
	while (++stuff->j < MT)
		pthread_join(stuff->th[stuff->j], NULL);
	mlx_put_image_to_window(stuff->img.mlx_ptr, stuff->img.win_ptr, \
		stuff->img.img_ptr, 0, 0);
}

void		*draw_burningship(t_tmp *tmp)
{
	double	temp;
	t_frac	frac;
	t_stuff	*stuff;

	stuff = tmp->stuff;
	set_data(tmp, &frac);
	while (++frac.x < frac.end)
	{
		frac.y = -1;
		while (++frac.y < LENGTH)
		{
			burning(&frac, stuff, temp);
			if (frac.i == stuff->frc.max_it)
				mlx_pixel_put_to_image(stuff->img, frac.x, frac.y, 0x000000);
			else
				mlx_pixel_put_to_image(stuff->img, frac.x, frac.y, \
					stuff->img.color[frac.i]);
		}
	}
	free(tmp);
	return (NULL);
}

void		burning(t_frac *frac, t_stuff *stuff, double temp)
{
	frac->c_r = (frac->x / WIDTH) * (frac->x2 - frac->x1) + frac->x1;
	frac->c_i = (frac->y / LENGTH) * (frac->y2 - frac->y1) + frac->y1;
	frac->z_r = 0;
	frac->z_i = 0;
	frac->i = -1;
	while (frac->z_r * frac->z_r + frac->z_i * frac->z_i < 4 && \
		++frac->i < stuff->frc.max_it)
	{
		temp = frac->z_r;
		frac->z_r = ((frac->z_r * frac->z_r) - (frac->z_i * frac->z_i)) \
		+ frac->c_r;
		frac->z_i = 2 * fabs(frac->z_i * temp) + frac->c_i;
	}
}
