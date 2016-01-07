/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/07 16:11:31 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		alti_max(int **map, int nbl, int nbn)
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

void	put_lines1(t_env e, int **map, int nbl, int nbn, float zoom)
{
	int		i;
	int		j;
	int		max;
	float	x;
	float	y;
	float	ys;
	float	xs;
	float	cx;
	float	cy;
	int		alti;
	t_xy	c;
	(void)map;

	j = 0;
	y = 200;
	x = 900;
	ys = y;
	xs = x;
	cx = 50 * zoom;
	cy = 25 * zoom;
	alti = 5;
	max = alti_max(map, nbl, nbn);
	while (j < nbl)
	{
		i = 0;
		while (i < nbn - 1)
		{
			c.xmin = x;
			c.xmax = x + cx;
			c.ymin = y - (map[j][i] * alti);
			c.ymax = y + cy - (map[j][i + 1] * alti);
			if (map[j][i] == 0)
				c.color = 0x003366;
			if ((map[j][i] > 0 && map[j][i] <= max / 4) || (map[j][i + 1] > 0 && map[j][i + 1] <= max / 4))
				c.color = 0x336688;
			if ((map[j][i] > max / 4 && map[j][i] <= max / 2) || (map[j][i + 1] > max / 4 && map[j][i + 1] <= max / 2))
				c.color = 0x6688AA;
			if ((map[j][i] > max / 2 && map[j][i] <= 3 * max / 4) || (map[j][i + 1] > max / 2 && map[j][i + 1] <= 3 * max / 4))
				c.color = 0x88AACC;
			if ((map[j][i] > 3 * max / 4 && map[j][i] <= max) || (map[j][i + 1] > 3 * max / 4 && map[j][i + 1] <= max))
				c.color = 0xAACCEE;
			put_line(c, e.mlx, e.win);
			y = ys + (cy * i);
			y += cy;
			x += cx;
			i++;
		}
		ys += cy;
		xs -= cx;
		y = ys;
		x = xs;
		j++;
	}
}

void	put_lines2(t_env e, int **map, int nbl, int nbn, float zoom)
{
	int		i;
	int		j;
	int		max;
	float	x;
	float	y;
	float	ys;
	float	xs;
	float	cx;
	float	cy;
	int		alti;
	t_xy	c;
	(void)map;

	i = 0;
	y = 200;
	x = 900;
	ys = y;
	xs = x;
	cx = 50 * zoom;
	cy = 25 * zoom;
	alti = 5;
	max = alti_max(map, nbl, nbn);
	while (i < nbn)
	{
		j = 0;
		while (j < nbl - 1)
		{
			c.xmin = x;
			c.xmax = x - cx;
			c.ymin = y - (map[j][i] * alti);
			c.ymax = y + cy - (map[j + 1][i] * alti);
			if (map[j][i] == 0)
				c.color = 0x003366;
			if ((map[j][i] > 0 && map[j][i] <= max / 4) || (map[j + 1][i] > 0 && map[j + 1][i] <= max / 4))
				c.color = 0x336688;
			if ((map[j][i] > max / 4 && map[j][i] <= max / 2) || (map[j + 1][i] > max / 4 && map[j + 1][i] <= max / 2))
				c.color = 0x6688AA;
			if ((map[j][i] > max / 2 && map[j][i] <= 3 * max / 4) || (map[j + 1][i] > max / 2 && map[j + 1][i] <= 3 * max / 4))
				c.color = 0x88AACC;
			if ((map[j][i] > 3 * max / 4 && map[j][i] <= max) || (map[j + 1][i] > 3 * max / 4 && map[j + 1][i] <= max))
				c.color = 0xAACCEE;
			put_line(c, e.mlx, e.win);
			y = ys + (cy * j);
			y += cy;
			x -= cx;
			j++;
		}
		ys += cy;
		xs += cx;
		y = ys;
		x = xs;
		i++;
	}
}


int		main(int ac, char **av)
{
	t_env	e;
	float zoom;
	int nbl;
	int **map;
	int nbn;

	(void)ac;
	nbn = 1;
	map = read_map(av[1], &nbl, &nbn);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2000, 1300, "42");
	zoom = 0.3;
	put_lines1(e, map, nbl, nbn, zoom);
	put_lines2(e, map, nbl, nbn, zoom);
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
