/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/09 10:40:02 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_swap(float *a, float *b)
{
	int c;

	c = *b;
	*b = *a;
	*a = c;
}

static void	line_horizon(t_xy c, void *mlx, void *win)
{
	float x;

	x = c.xmin;
	while (x <= c.xmax)
	{
		mlx_pixel_put(mlx, win, x, c.ymin, c.color);
		x++;
	}
}

static void	line_verti(t_xy c, void *mlx, void *win)
{
	float y;

	y = c.ymin;
	while (y <= c.ymax)
	{
		mlx_pixel_put(mlx, win, c.xmin, y, c.color);
		y++;
	}
}

static void	line_diago(t_xy c, void *mlx, void *win)
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
			mlx_pixel_put(mlx, win, v.x, v.y, c.color);
			v.y += v.m / v.preci;
			v.i++;
		}
		v.x++;
	}
}

void		put_line(t_xy c, void *mlx, void *win)
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
		line_verti(c, mlx, win);
	else if (c.ymax == c.ymin)
		line_horizon(c, mlx, win);
	else
		line_diago(c, mlx, win);
}
