/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:15:02 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/08 16:28:23 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	events(int keycode, t_ray *m)
{
	if (keycode == R)
		principal_menu(m, 1);
	if (keycode == ONE || keycode == ONE2)
		commands(m);
	if (keycode == TWO || keycode == TWO2)
		resolution(m);
	if (keycode == ESC)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(0);
	}
	return (0);
}

void		options(t_ray *m)
{
	int x;
	int y;

	y = m->sh / 2 - 100;
	while (++y < m->sh / 2 + 300)
	{
		x = m->sh / 2 - 200;
		while (++x < m->sh / 2 + 800)
			mlx_pixel_put(m->mlx, m->win, x, y, 0);
	}
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 60, m->sh / 2, 0xffff,
			"1 : COMMANDS");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 70, m->sh / 2 + 30, 0xffff,
			"2 : RESOLUTION");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 50, m->sh / 2 + 60, 0xffff,
			"R : RETURN");
	mlx_key_hook(m->win, events, m);
	mlx_loop(m->mlx);
}
