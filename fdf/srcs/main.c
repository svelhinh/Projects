/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/30 16:38:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y)
{
	(void)button;
	printf("x = %d\ny = %d\n\n", x, y);
	return (0);
}

void	appel_yo(t_env e, int nblines)
{
	t_xy	c;
	int i;

	i = 0;
	c.color = 16777215;
	c.xmin = 500;
	c.xmax = 100;
	c.ymin = 100;
	c.ymax = 400;
	while (i < nblines)
	{
		yo(c, e.mlx, e.win);
		c.xmin += 30;
		c.xmax += 30;
		c.ymin += 20;
		c.ymax += 20;
		i++;
	}
}

int		main(void)
{
	t_env	e;
	int nblines;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1300, 1000, "42");
	nblines = 19;
	appel_yo(e, nblines);
	// DEBUG
	/*c.xmin = 500;
	c.xmax = 100;
	c.ymin = 500;
	c.ymax = 100;
	yo(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 500;
	c.ymin = 500;
	c.ymax = 100;
	yo(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 900;
	c.ymin = 500;
	c.ymax = 100;
	yo(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 900;
	c.ymin = 500;
	c.ymax = 500;
	yo(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 900;
	c.ymin = 500;
	c.ymax = 900;
	yo(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 500;
	c.ymin = 500;
	c.ymax = 900;
	yo(c, e.mlx, e.win);
	c.xmin = 500;
	c.xmax = 100;
	c.ymin = 500;
	c.ymax = 900;
	yo(c, e.mlx, e.win);
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
