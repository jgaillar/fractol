/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 22:10:07 by jgaillar          #+#    #+#             */
/*   Updated: 2017/08/07 11:13:07 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define WIDTH 800
# define LENGTH 800
# define IT 100
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <pthread.h>
# include <math.h>
# include <../libft/libft.h>

# define MT 16

typedef struct		s_frc
{
	int				i;
	int				lock;
	double			x;
	double			y;
	double			start;
	double			end;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			max_it;
	double			zoom;

}					t_frc;

typedef struct		s_frac
{
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				i;
	double			x;
	double			y;
	double			end;
}					t_frac;

typedef struct		s_img
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				size;
	int				color[51];
	char			*data;
}					t_img;

typedef	struct		s_stuff
{
	t_img			img;
	t_frc			frc;
	pthread_t		*th;
	unsigned long	i;
	unsigned long	j;
	int				exit;
	int				type;
	double			tmp;
}					t_stuff;

typedef	struct		s_tmp
{
	t_stuff			*stuff;
	double			start;
	double			end;
}					t_tmp;

void				mlx_pixel_put_to_image(t_img img, int x, int y, int color);
void				ft_exit(int code);
int					refresh(t_stuff *stuff);
void				init_struct(t_stuff *stuff);
void				init_frac(t_stuff *stuff);
void				julia(t_stuff *stuff);
void				*draw_julia(t_tmp *tmp);
int					draw(t_stuff *stuff);
void				create_image(t_stuff *stuff);
void				mandelbrot(t_stuff *stuff);
void				burningship(t_stuff *stuff);
void				burning(t_frac *frac, t_stuff *stuff, double temp);
void				juliahelp(t_frac *frac, t_stuff *stuff, double temp);
void				mandel(t_frac *frac, t_stuff *stuff, double temp);
void				*draw_mandelbrot(t_tmp *tmp);
void				*draw_burningship(t_tmp *tmp);
void				set_data(t_tmp *tmp, t_frac *frac);
void				color1(t_img *img);
void				color2(t_img *img);
void				color3(t_img *img);
void				controlhelp(void);
int					hooks(int keycode, t_stuff *stuff);
void				echap(int keycode, t_stuff *stuff);
void				hormovement(int keycode, t_stuff *stuff);
void				vermovement(int keycode, t_stuff *stuff);
void				itehook(int keycode, t_stuff *stuff);
int					mouse_hook(int x, int y, t_stuff *stuff);
int					zoom(int button, int x, int y, t_stuff *stuff);
void				plus(t_stuff *stuff, int x, int y);
void				minus(t_stuff *stuff, int x, int y);
#endif
