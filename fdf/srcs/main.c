/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/31 17:49:10 by svelhinh         ###   ########.fr       */
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

void	appel_yo(t_env e, int nblinesg, int nblinesd)
{
	t_xy	c;
	int		coeffx;
	int		coeffy;
	int		l;
	int		h;
	int		i;
	(void)nblinesd;

	i = 1;
	coeffx = 50;
	coeffy = 25;
	c.color = 16777215;
	c.xmin = 700;
	l = 50;
	c.ymin = 200;
	h = 25;
	while (i <= nblinesg)
	{
		printf("i = %d\n", i);
		c.xmax = c.xmin - l;
		c.ymax = c.ymin + h;
		yo(c, e.mlx, e.win);
		c.xmin = c.xmax;
		c.ymin = c.ymax;
		i++;
	}
}

int		main(void)
{
	t_env	e;
	int nblinesg;
	int nblinesd;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2000, 2000, "42");
	nblinesd = 10;
	nblinesg = 10;
	appel_yo(e, nblinesg, nblinesd);
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
