/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:36:33 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/12 17:33:50 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		alti_max(float **map, int nbl, int nbn)
{
	int		y;
	int		x;
	float	max;

	y = 0;
	max = 0;
	while (y < nbl)
	{
		x = 0;
		while (x < nbn)
		{
			if (map[y][x] > max)
				max = map[y][x];
			x++;
		}
		y++;
	}
	return (max);
}

int		alti_min(float **map, int nbl, int nbn)
{
	int		y;
	int		x;
	float	min;

	y = 0;
	min = 2147483647;
	while (y < nbl)
	{
		x = 0;
		while (x < nbn)
		{
			if (map[y][x] < min)
				min = map[y][x];
			x++;
		}
		y++;
	}
	return (min);
}

void	put_lines1(t_fdf v)
{
	t_xy	c;

	c = init_var(c, v);
	while (c.j < v.nbl && !(c.i = 0))
	{
		while (c.i < v.nbn - 1)
		{
			c.xmin = c.x;
			c.xmax = c.x + c.cx;
			c.ymin = c.y - (v.map[c.j][c.i] * v.alti);
			c.ymax = c.y + c.cy - (v.map[c.j][c.i + 1] * v.alti);
			c.color = color(1, 0, c, v);
			c.colorv = mlx_get_color_value(v.mlx, c.color);
			put_line(c, v);
			c.y = c.ys + (c.cy * c.i);
			c.y += c.cy;
			c.x += c.cx;
			c.i++;
		}
		c.ys += c.cy;
		c.xs -= c.cx;
		c.y = c.ys;
		c.x = c.xs;
		c.j++;
	}
}

void	put_lines2(t_fdf v)
{
	t_xy	c;

	c = init_var(c, v);
	while (c.i < v.nbn && !(c.j = 0))
	{
		while (c.j < v.nbl - 1)
		{
			c.xmin = c.x;
			c.xmax = c.x - c.cx;
			c.ymin = c.y - (v.map[c.j][c.i] * v.alti);
			c.ymax = c.y + c.cy - (v.map[c.j + 1][c.i] * v.alti);
			c.color = color(0, 1, c, v);
			c.colorv = mlx_get_color_value(v.mlx, c.color);
			put_line(c, v);
			c.y = c.ys + (c.cy * c.j);
			c.y += c.cy;
			c.x -= c.cx;
			c.j++;
		}
		c.ys += c.cy;
		c.xs += c.cx;
		c.y = c.ys;
		c.x = c.xs;
		c.i++;
	}
}
