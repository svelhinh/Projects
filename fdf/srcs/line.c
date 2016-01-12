/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/12 17:22:33 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mlx_pixel_put_to_img(t_xy c, t_fdf *v, int x, int y)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	b = (c.colorv & 0xFF0000) >> 16;
	g = (c.colorv & 0xFF00) >> 8;
	r = (c.colorv & 0xFF);
	if (y > 0 && x > 0 && x < v->width && y < v->height)
	{
		v->data[y * v->size_line + x * v->bpp / 8] = r;
		v->data[y * v->size_line + x * v->bpp / 8 + 1] = g;
		v->data[y * v->size_line + x * v->bpp / 8 + 2] = b;
	}
}

static void	line_horizon(t_xy c, t_fdf v)
{
	float x;

	x = c.xmin;
	while (x <= c.xmax)
	{
		mlx_pixel_put_to_img(c, &v, x, c.ymin);
		x++;
	}
}

static void	line_verti(t_xy c, t_fdf v)
{
	float y;

	y = c.ymin;
	while (y <= c.ymax)
	{
		mlx_pixel_put_to_img(c, &v, c.xmin, y);
		y++;
	}
}

static void	line_diago(t_xy c, t_fdf v2)
{
	t_xy v;

	v.dx = c.xmax - c.xmin;
	v.dy = c.ymax - c.ymin;
	v.m = v.dy / v.dx;
	v.y = c.ymin;
	v.x = c.xmin;
	v.preci = 10;
	while (v.x < c.xmax)
	{
		v.i = 0;
		while (v.i < v.preci)
		{
			mlx_pixel_put_to_img(c, &v2, v.x, v.y);
			v.y += v.m / v.preci;
			v.i++;
		}
		v.x++;
	}
}

void		put_line(t_xy c, t_fdf v)
{
	if (c.xmin > c.xmax && c.ymin > c.ymax)
	{
		ft_swap(&c.ymin, &c.ymax);
		ft_swap(&c.xmin, &c.xmax);
	}
	else
	{
		if (c.ymin > c.ymax)
		{
			(c.xmin < c.xmax) ? (ft_swap(&c.xmin, &c.xmax))
				: (ft_swap(&c.ymin, &c.ymax));
		}
		if (c.xmin > c.xmax)
		{
			(c.ymin < c.ymax) ? ft_swap(&c.ymin, &c.ymax) : (0);
			ft_swap(&c.xmin, &c.xmax);
		}
	}
	if (c.xmax == c.xmin)
		line_verti(c, v);
	else if (c.ymax == c.ymin)
		line_horizon(c, v);
	else
		line_diago(c, v);
}
