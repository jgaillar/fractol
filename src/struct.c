/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:53:44 by jgaillar          #+#    #+#             */
/*   Updated: 2017/04/05 16:54:41 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_struct(t_stuff *stuff)
{
	stuff->frc.x1 = -1;
	stuff->frc.x2 = 1;
	stuff->frc.y1 = -1.2;
	stuff->frc.y2 = 1.2;
	stuff->frc.MAX_IT = 50;
	color1(stuff);
	stuff->frc.ZOOMX = LENGTH/(stuff->frc.x2 - stuff->frc.x1);
	stuff->frc.ZOOMY = WIDTH/(stuff->frc.y2 - stuff->frc.y1);
	stuff->img.img_ptr = mlx_new_image(stuff->img.mlx_ptr, WIDTH, LENGTH);
	if (!(stuff->img.data = (char *)ft_strnew(sizeof(char)\
		* WIDTH * LENGTH * 4)))
		exit(0);
	stuff->img.data = mlx_get_data_addr(stuff->img.img_ptr,\
		&stuff->img.bits_per_pixel, &stuff->img.size_line, &stuff->img.endian);
}
