/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:16:03 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/20 17:40:41 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <complex.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# define WIDTH 1000
# define HEIGHT 700

typedef struct			s_fract
{
	void				*mlx;
	void				*win;
	char				*fract;
	void				*img;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
	float				x1;
	float				x2;
	float				y1;
	float				y2;
	int					x;
	int					y;
	float				coeffx;
	float				coeffy;
	float				fractx;
	float				fracty;
	float				zoom;
	int					color;
	int					i;
	int					i_max;
	int					i_max_base;
	_Complex float		z;
	_Complex float		c;
	float				x_reel;
	float				y_reel;
	float				factor;
}						t_fract;
int						draw(t_fract *e);
void					mandelbrot(t_fract e);
void					illuminati(t_fract e);
void					waterdrop(t_fract e);
void					eye(t_fract e);
void					salad(t_fract e);
void					star(t_fract e);
void					julia(t_fract e);
void					mlx_pixel_put_to_image(t_fract *e);
int						key(int keycode, t_fract *e);
int						mouse(int x, int y, t_fract *e);
int						zoom(int button, int x, int y, t_fract *e);
void					var_init(t_fract *e);
#endif
