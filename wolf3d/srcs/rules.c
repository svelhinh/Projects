/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:33:30 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/09 12:05:43 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	events(int keycode, t_ray *m)
{
	if (keycode == R)
		options(m);
	if (keycode == ESC)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(0);
	}
	return (0);
}

static void	rules(t_ray *m)
{
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 260, m->sh / 2 + 150, 0xff00,
		"Find the exit of the labyrinth in the shortest time");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 50, m->sh / 2 + 210, 0xffff,
			"R : RETURN");
}

void		commands(t_ray *m)
{
	int x;
	int y;

	y = m->sh / 2;
	while (++y < m->sh / 2 + 100)
	{
		x = m->sw / 2 - 100;
		while (++x < m->sw / 2 + 200)
			mlx_pixel_put(m->mlx, m->win, x, y, 0);
	}
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 115, m->sh / 2 - 90, 0xffff00,
			"UP or W -> MOVE FORWARD");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 110, m->sh / 2 - 60, 0xffff00,
			"DOWN or S -> MOVE BACK");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 120, m->sh / 2 - 30, 0xffff00,
			"LEFT or A -> ROTATE LEFT");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 130, m->sh / 2, 0xffff00,
			"RIGHT or D -> ROTATE RIGHT");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 50, m->sh / 2 + 30, 0xffff00,
			"P -> PAUSE");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 50, m->sh / 2 + 60, 0xffff00,
			"R -> RETRY");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 80, m->sh / 2 + 90, 0xffff00,
			"ESC -> QUIT GAME");
	rules(m);
	mlx_key_hook(m->win, events, m);
	mlx_loop(m->mlx);
}
