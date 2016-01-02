/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/02 12:37:57 by svelhinh         ###   ########.fr       */
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

void	linesd(t_env e, int nblinesd, int nblinesg)
{
	t_xy	c;
	float	l;
	float	h;
	int		i;
	int		j;
	int		sxmin;
	int		symin;

	c.color = 16777215;
	c.xmin = 1200;
	l = 50;
	c.ymin = 200;
	h = l / 2;
	j = 1;
	sxmin = c.xmin;
	symin = c.ymin;
	while (j <= nblinesd - (nblinesd - nblinesg))
	{
		i = 1;
		while (i < nblinesd)
		{
			c.xmax = c.xmin - l;
			c.ymax = c.ymin + h;
			yo(c, e.mlx, e.win);
			c.xmin = c.xmax;
			c.ymin = c.ymax;
			i++;
		}
		c.xmin = sxmin + l;
		c.ymin = symin + h;
		sxmin = c.xmin;
		symin = c.ymin;
		j++;
	}
}

void	linesg(t_env e, int nblinesd, int nblinesg)
{
	t_xy	c;
	float	l;
	float	h;
	int		i;
	int		j;
	int		sxmin;
	int		symin;

	c.color = 16777215;
	c.xmin = 1200;
	l = 50;
	c.ymin = 200;
	h = l / 2;
	j = 1;
	sxmin = c.xmin;
	symin = c.ymin;
	while (j <= nblinesg + (nblinesd - nblinesg))
	{
		i = 1;
		while (i < nblinesg)
		{
			c.xmax = c.xmin + l;
			c.ymax = c.ymin + h;
			yo(c, e.mlx, e.win);
			c.xmin = c.xmax;
			c.ymin = c.ymax;
			i++;
		}
		c.xmin = sxmin - l;
		c.ymin = symin + h;
		sxmin = c.xmin;
		symin = c.ymin;
		j++;
	}
}



int		main(void)
{
	t_env	e;
	int nblinesg;
	int nblinesd;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2000, 2000, "42");
	nblinesd = 19;
	nblinesg = 11;
	linesg(e, nblinesd, nblinesg);
	linesd(e, nblinesd, nblinesg);
	//appel_yo(e, nblinesg, nblinesd, sens);
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
