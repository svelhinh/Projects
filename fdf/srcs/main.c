/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/04 17:48:35 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_lines1(t_env e, int **map, int nbl, int nbn, float zoom)
{
	int		i;
	int		j;
	float	x;
	float	y;
	float	ys;
	float	xs;
	float	cx;
	float	cy;
	int		alti;
	t_xy	c;

	j = 0;
	y = 700;
	x = 900;
	ys = y;
	xs = x;
	cx = 50 * zoom;
	cy = 25 * zoom;
	alti = 20;
	while (j < nbl)
	{
		i = 0;
		while (i < nbn)
		{
			y -= (map[j][i] * alti);
			c.xmin = x;
			c.xmax = x + cx;
			if (map[j][i - 1] > map[j][i])
				c.ymin = y - ((map[j][i - 1] - map[j][i]) * alti);
			else
				c.ymin = y;
			if (map[j][i] < map[j][i + 1])
				c.ymax = y + cy - ((map[j][i + 1] - map[j][i]) * alti);
			else
				c.ymax = y + cy;
			c.color = 16777215;
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
	y = 700;
	x = 900;
	ys = y;
	xs = x;
	cx = 50 * zoom;
	cy = 25 * zoom;
	alti = 20;
	while (j < nbn)
	{
		i = 0;
		while (i < nbl)
		{
			y -= (map[i][j] * alti);
			c.xmin = x;
			c.xmax = x - cx;
			c.ymin = y;
			c.ymax = y + cy;
			c.color = 16777215;
			put_line(c, e.mlx, e.win);
			y = ys + (cy * i);
			y += cy;
			x -= cx;
			i++;
		}
		ys += cy;
		xs += cx;
		y = ys;
		x = xs;
		j++;
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
	nbn = 0;
	map = read_map(av[1], &nbl, &nbn);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2000, 1500, "42");
	zoom = 1;
	put_lines1(e, map, nbl, nbn, zoom);
	//put_lines2(e, map, nbl, nbn, zoom);
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
