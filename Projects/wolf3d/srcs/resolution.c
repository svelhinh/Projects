/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:18:42 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/08 16:34:52 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	change(int keycode, t_ray *m)
{
	if (keycode == ONE || keycode == ONE2 || keycode == TWO || keycode == TWO2
			|| keycode == THREE || keycode == THREE2)
	{
		mlx_destroy_window(m->mlx, m->win);
		principal_menu(m, 0);
	}
}

static int	events(int keycode, t_ray *m)
{
	if (keycode == R)
		options(m);
	if (keycode == ONE || keycode == ONE2)
	{
		m->sw = 800;
		m->sh = 600;
	}
	if (keycode == TWO || keycode == TWO2)
	{
		m->sw = 1024;
		m->sh = 768;
	}
	if (keycode == THREE || keycode == THREE2)
	{
		m->sw = 1920;
		m->sh = 1080;
	}
	change(keycode, m);
	if (keycode == ESC)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(0);
	}
	return (0);
}

void		resolution(t_ray *m)
{
	int x;
	int y;

	y = m->sh / 2;
	while (++y < m->sh / 2 + 100)
	{
		x = m->sw / 2 - 100;
		while (++x < m->sw / 2 + 100)
			mlx_pixel_put(m->mlx, m->win, x, y, 0);
	}
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 55, m->sh / 2, 0xffff,
			"1 : 800x600");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 60, m->sh / 2 + 30, 0xffff,
			"2 : 1024x768");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 65, m->sh / 2 + 60, 0xffff,
			"3 : 1920x1080");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 50, m->sh / 2 + 90, 0xffff,
			"R : RETURN");
	mlx_key_hook(m->win, events, m);
	mlx_loop(m->mlx);
}
