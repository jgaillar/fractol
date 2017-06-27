/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:10:07 by jgaillar          #+#    #+#             */
/*   Updated: 2017/06/24 02:40:27 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define WIDTH 800
# define LENGTH 800
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <../libft/libft.h>

typedef struct	s_frc
{
	int		i;
	double x;
	double y;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	double x1;
	double x2;
	double y1;
	double y2;
	double zoom;
	double ZOOMX;
	double ZOOMY;
	double MAX_IT;

}				t_frc;

typedef struct	s_img
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			size;
	int			color[51];
	char		*data;
}				t_img;

typedef	struct	s_stuff
{
	t_img		img;
	t_frc		frc;
	int			type;
}				t_stuff;

void			mlx_pixel_put_to_image(t_img img, int x, int y, int color);
void			ft_exit(int code);
static void		ft_usage(void);
void			init_struct(t_stuff *stuff, int option);
void				julia(t_stuff *stuff);
int				draw(t_stuff *stuff);
void			mandelbrot(t_stuff *stuff);
void			color1(t_stuff *stuff);
int				hooks(int keycode, t_stuff *stuff);
void			echap(int keycode, t_stuff *stuff);
void			hormovement(int keycode, t_stuff *stuff);
void			vermovement(int keycode, t_stuff *stuff);
void			refresh(t_stuff *stuff);
void		itehook(int keycode, t_stuff *stuff);
#endif
