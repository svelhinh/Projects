/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:36:33 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/10 11:43:01 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		alti_max(float **map, int nbl, int nbn)
{
	int y;
	int x;
	int max;

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
	int y;
	int x;
	int min;

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

int		color(int i2, int j2, t_xy c, t_fdf v)
{
	if (v.map[c.j][c.i] == c.min)
		c.color = 0x003366;
	if ((v.map[c.j][c.i] > c.min && v.map[c.j][c.i] <= c.max / 4)
			|| (v.map[c.j + j2][c.i + i2] > c.min
				&& v.map[c.j + j2][c.i + i2] <= c.max / 4))
		c.color = 0x336688;
	if ((v.map[c.j][c.i] > c.max / 4 && v.map[c.j][c.i] <= c.max / 2)
			|| (v.map[c.j + j2][c.i + i2] > c.max / 4
				&& v.map[c.j + j2][c.i + i2] <= c.max / 2))
		c.color = 0x6688AA;
	if ((v.map[c.j][c.i] > c.max / 2 && v.map[c.j][c.i] <= 3 * c.max / 4)
			|| (v.map[c.j + j2][c.i + i2] > c.max / 2
				&& v.map[c.j + j2][c.i + i2] <= 3 * c.max / 4))
		c.color = 0x88AACC;
	if ((v.map[c.j][c.i] > 3 * c.max / 4 && v.map[c.j][c.i] <= c.max)
			|| (v.map[c.j + j2][c.i + i2] > 3 * c.max / 4
				&& v.map[c.j + j2][c.i + i2] <= c.max))
		c.color = 0xAACCEE;
	return (c.color);
}

void	put_lines1(t_env e, t_fdf v, float alti)
{
	t_xy	c;

	c = init_var(c, v);
	while (c.j < v.nbl)
	{
		c.i = 0;
		while (c.i < v.nbn - 1)
		{
			c.xmin = c.x;
			c.xmax = c.x + c.cx;
			c.ymin = c.y - (v.map[c.j][c.i] * alti);
			c.ymax = c.y + c.cy - (v.map[c.j][c.i + 1] * alti);
			c.color = color(1, 0, c, v);
			put_line(c, e.mlx, e.win);
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

void	put_lines2(t_env e, t_fdf v, float alti)
{
	t_xy	c;

	c = init_var(c, v);
	while (c.i < v.nbn)
	{
		c.j = 0;
		while (c.j < v.nbl - 1)
		{
			c.xmin = c.x;
			c.xmax = c.x - c.cx;
			c.ymin = c.y - (v.map[c.j][c.i] * alti);
			c.ymax = c.y + c.cy - (v.map[c.j + 1][c.i] * alti);
			c.color = color(0, 1, c, v);
			put_line(c, e.mlx, e.win);
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
