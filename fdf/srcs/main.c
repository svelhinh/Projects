/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/08 17:39:43 by svelhinh         ###   ########.fr       */
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

void	put_lines1(t_env e, t_fdf v, float alti)
{
	t_xy	n;
	t_xy	c;

	n.j = 0;
	n.y = 100;
	n.x = 1100;
	n.ys = n.y;
	n.xs = n.x;
	n.cx = 50 * v.zoom;
	n.cy = 25 * v.zoom;
	n.min = alti_min(v.map, v.nbl, v.nbn);
	n.max = alti_max(v.map, v.nbl, v.nbn) - n.min;
	while (n.j < v.nbl)
	{
		n.i = 0;
		while (n.i < v.nbn - 1)
		{
			c.xmin = n.x;
			c.xmax = n.x + n.cx;
			c.ymin = n.y - (v.map[n.j][n.i] * alti);
			c.ymax = n.y + n.cy - (v.map[n.j][n.i + 1] * alti);
			if (v.map[n.j][n.i] == n.min)
				c.color = 0x003366;
			if ((v.map[n.j][n.i] > n.min && v.map[n.j][n.i] <= n.max / 4) || (v.map[n.j][n.i + 1] > n.min && v.map[n.j][n.i + 1] <= n.max / 4))
				c.color = 0x336688;
			if ((v.map[n.j][n.i] > n.max / 4 && v.map[n.j][n.i] <= n.max / 2) || (v.map[n.j][n.i + 1] > n.max / 4 && v.map[n.j][n.i + 1] <= n.max / 2))
				c.color = 0x6688AA;
			if ((v.map[n.j][n.i] > n.max / 2 && v.map[n.j][n.i] <= 3 * n.max / 4) || (v.map[n.j][n.i + 1] > n.max / 2 && v.map[n.j][n.i + 1] <= 3 * n.max / 4))
				c.color = 0x88AACC;
			if ((v.map[n.j][n.i] > 3 * n.max / 4 && v.map[n.j][n.i] <= n.max) || (v.map[n.j][n.i + 1] > 3 * n.max / 4 && v.map[n.j][n.i + 1] <= n.max))
				c.color = 0xAACCEE;
			put_line(c, e.mlx, e.win);
			n.y = n.ys + (n.cy * n.i);
			n.y += n.cy;
			n.x += n.cx;
			n.i++;
		}
		n.ys += n.cy;
		n.xs -= n.cx;
		n.y = n.ys;
		n.x = n.xs;
		n.j++;
	}
}

void	put_lines2(t_env e, t_fdf v, float alti)
{
	t_xy	n;
	t_xy	c;

	n.i = 0;
	n.y = 100;
	n.x = 1100;
	n.ys = n.y;
	n.xs = n.x;
	n.cx = 50 * v.zoom;
	n.cy = 25 * v.zoom;
	n.max = alti_max(v.map, v.nbl, v.nbn);
	n.min = alti_min(v.map, v.nbl, v.nbn);
	while (n.i < v.nbn)
	{
		n.j = 0;
		while (n.j < v.nbl - 1)
		{
			c.xmin = n.x;
			c.xmax = n.x - n.cx;
			c.ymin = n.y - (v.map[n.j][n.i] * alti);
			c.ymax = n.y + n.cy - (v.map[n.j + 1][n.i] * alti);
			if (v.map[n.j][n.i] == n.min)
				c.color = 0x003366;
			if ((v.map[n.j][n.i] > n.min && v.map[n.j][n.i] <= n.max / 4) || (v.map[n.j + 1][n.i] > n.min && v.map[n.j + 1][n.i] <= n.max / 4))
				c.color = 0x336688;
			if ((v.map[n.j][n.i] > n.max / 4 && v.map[n.j][n.i] <= n.max / 2) || (v.map[n.j + 1][n.i] > n.max / 4 && v.map[n.j + 1][n.i] <= n.max / 2))
				c.color = 0x6688AA;
			if ((v.map[n.j][n.i] > n.max / 2 && v.map[n.j][n.i] <= 3 * n.max / 4) || (v.map[n.j + 1][n.i] > n.max / 2 && v.map[n.j + 1][n.i] <= 3 * n.max / 4))
				c.color = 0x88AACC;
			if ((v.map[n.j][n.i] > 3 * n.max / 4 && v.map[n.j][n.i] <= n.max) || (v.map[n.j + 1][n.i] > 3 * n.max / 4 && v.map[n.j + 1][n.i] <= n.max))
				c.color = 0xAACCEE;
			put_line(c, e.mlx, e.win);
			n.y = n.ys + (n.cy * n.j);
			n.y += n.cy;
			n.x -= n.cx;
			n.j++;
		}
		n.ys += n.cy;
		n.xs += n.cx;
		n.y = n.ys;
		n.x = n.xs;
		n.i++;
	}
}


int		main(int ac, char **av)
{
	t_env	e;
	t_fdf	v;
	float	alti;

	(void)ac;
	v.nbn = 1;
	v.map = read_map(av[1], &v.nbl, &v.nbn);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2000, 1300, "42");
	v.zoom = 0.03;
	alti = 5 * v.zoom;
	put_lines1(e, v, alti);
	put_lines2(e, v, alti);
	// DEBUG
	/*c.xmin = 500;
	c.xmax = 100;
	c.ymin = 500;
	c.ymax = 100;
	put_line(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 500;
	c.ymin = 500;
	c.ymax = 100;
	put_line(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 900;
	c.ymin = 500;
	c.ymax = 100;
	put_line(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 900;
	c.ymin = 500;
	c.ymax = 500;
	put_line(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 900;
	c.ymin = 500;
	c.ymax = 900;
	put_line(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 500;
	c.ymin = 500;
	c.ymax = 900;
	put_line(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 100;
	c.ymin = 500;
	c.ymax = 900;
	put_line(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 100;
	c.ymin = 500;
	c.ymax = 500;*/
	// FIN DU DEBUG
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
