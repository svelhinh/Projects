/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/02 11:30:17 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(float *a, float *b)
{
	int c;

	c = *b;
	*b = *a;
	*a = c;
}

void	line_horizon(t_xy c, void *mlx, void *win)
{
	float x;

	x = c.xmin;
	while (x <= c.xmax)
	{
		mlx_pixel_put(mlx, win, x, c.ymin, c.color);
		x++;
	}
}

void	line_verti(t_xy c, void *mlx, void *win)
{
	float y;

	y = c.ymin;
	while (y <= c.ymax)
	{
		mlx_pixel_put(mlx, win, c.xmin, y, c.color);
		y++;
	}
}

void	line_diago(t_xy c, void *mlx, void *win)
{
	int x;
	float dx;
	float dy;
	float m;
	float y;

	dx = c.xmax - c.xmin;
	dy = c.ymax - c.ymin;
	m = dy / dx;
	y = c.ymin;
	x = c.xmin;
	while (x <= c.xmax)
	{
		mlx_pixel_put(mlx, win, x, y, c.color);
		y += m;
		x++;
	}
}

void	yo(t_xy c, void *mlx, void *win)
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
			if (c.xmin < c.xmax)
				ft_swap(&c.xmin, &c.xmax);
			else if (c.xmin > c.xmax)
				ft_swap(&c.ymin, &c.ymax);
			else
				ft_swap(&c.ymin, &c.ymax);
		}
		if (c.xmin > c.xmax)
		{
			(c.ymin < c.ymax) ? ft_swap(&c.ymin, &c.ymax) : (NULL);
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
