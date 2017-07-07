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
	if (stuff->type == 1)
	{
		stuff->frc.x1 = -2.1;
		stuff->frc.x2 = 0.6;
		stuff->frc.zoom = 282;
	}
	else if (stuff->type == 2)
	{
		stuff->frc.c_r = 0.285;
		stuff->frc.c_i = 0.01;
		stuff->frc.x1 = -1.2;
		stuff->frc.x2 = 1;
		stuff->frc.zoom = 341;
	}
	if (!(stuff->th = (pthread_t *)malloc(sizeof(pthread_t) * MT)))
		exit(0);
	stuff->frc.start = WIDTH/MT;
	stuff->exit = 1;
	stuff->frc.y1 = -1.2;
	stuff->frc.y2 = 1.2;
	stuff->frc.MAX_IT = it;
	color1(&stuff->img);
	stuff->img.img_ptr = mlx_new_image(stuff->img.mlx_ptr, WIDTH, LENGTH);
	if (!(stuff->img.data = (char *)ft_strnew(sizeof(char)\
		* WIDTH * LENGTH * 4)))
		exit(0);
	stuff->img.data = mlx_get_data_addr(stuff->img.img_ptr,\
		&stuff->img.bits_per_pixel, &stuff->img.size_line, &stuff->img.endian);
}

// pour julia : modifier c_r et c_i avec le x et y de la souris en faisant en sorte qu'il soit entre -1 et 1
// pour le zoom faire en sorte que le centre de l'ecran soit le x et y que donne la souris
