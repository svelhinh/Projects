/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/03 15:23:45 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_points(t_env e, int **map, int nbl, int nbn, float zoom)
{
	int		i;
	int		j;
	float	x;
	float	y;
	float	ys;
	float	xs;
	float	cx;
	float	cy;
	t_xy	c;

	j = 0;
	y = 200;
	x = 900;
	ys = y;
	xs = x;
	cx = 50 * zoom;
	cy = 25 * zoom;
	while (j < nbl)
	{
		i = 0;
		while (i < nbn)
		{
			y -= map[j][i];
			c.xmin = x;
			c.xmax = x + cx;
			c.ymin = y;
			c.ymax = y + cy;
			c.color = 16777215;
			put_line(c, e.mlx, e.win);
			y = ys + (cy * i);
			x += cx;
			y += cy;
			i++;
		}
		ys += cy;
		xs -= cx;
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
	e.win = mlx_new_window(e.mlx, 2000, 1000, "42");
	zoom = 1;
	put_points(e, map, nbl, nbn, zoom);
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
