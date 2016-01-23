/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/23 11:31:45 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		mlx_pixel_put_to_img(t_coords *c, int x, int y)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	b = (c->color & 0xFF0000) >> 16;
	g = (c->color & 0xFF00) >> 8;
	r = (c->color & 0xFF);
	c->data[y * c->size_line + x * c->bpp / 8] = r;
	c->data[y * c->size_line + x * c->bpp / 8 + 1] = g;
	c->data[y * c->size_line + x * c->bpp / 8 + 2] = b;
}

static void	line_horizon(t_coords c)
{
	float x;

	x = c.xmin;
	while (x <= c.xmax)
	{
		mlx_pixel_put_to_img(&c, x, c.ymin);
		x++;
	}
}

static void	line_verti(t_coords c)
{
	float y;

	y = c.ymin;
	while (y <= c.ymax)
	{
		mlx_pixel_put_to_img(&c, c.xmin, y);
		y++;
	}
}

static void	line_diago(t_coords c)
{
	float	y;
	float	x;
	float	preci;
	int		i;

	c.dx = c.xmax - c.xmin;
	c.dy = c.ymax - c.ymin;
	c.m = c.dy / c.dx;
	y = c.ymin;
	x = c.xmin;
	preci = 10;
	while (x < c.xmax)
	{
		i = 0;
		while (i < preci)
		{
			mlx_pixel_put_to_img(&c, x, y);
			y += c.m / preci;
			i++;
		}
		x++;
	}
}

void		put_line(t_coords c)
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
		line_verti(c);
	else if (c.ymax == c.ymin)
		line_horizon(c);
	else
		line_diago(c);
}
