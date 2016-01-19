/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:16:03 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/19 17:46:09 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <complex.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# define WIDTH 500
# define HEIGHT 350

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
	_Complex float		z;
	_Complex float		c;
}						t_fract;
int						draw(t_fract *e);
void					mandelbrot(t_fract e);
void					julia(t_fract e);
void					mlx_pixel_put_to_image(t_fract *e);
int						key(int keycode);
int						mouse(int x, int y, t_fract *e);
int						zoom(int button, int x, int y, t_fract *e);
void					var_init(t_fract *e);
#endif
