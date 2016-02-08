/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:59:30 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/08 11:40:41 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char	*ft_random(void)
{
	char	*lvl;
	char	*tmp;
	char	*tmp2;
	int		nb_alea;

	srand(time(NULL));
	nb_alea = rand() % 3;
	tmp = ft_strdup("levels/lvl");
	tmp2 = ft_itoa(nb_alea);
	lvl = ft_strjoin(tmp, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (lvl);
}

static void	levels(int keycode, t_ray *m)
{
	if (keycode == ZERO || keycode == ZERO2 || keycode == ONE
			|| keycode == ONE2 || keycode == TWO || keycode == TWO2
			|| keycode == THREE || keycode == THREE2)
	{
		mlx_destroy_window(m->mlx, m->win);
		main2(*m);
	}
}

static int	events(int keycode, t_ray *m)
{
	if (keycode == R)
	{
		mlx_destroy_window(m->mlx, m->win);
		menu(m);
	}
	if (keycode == ZERO || keycode == ZERO2)
		m->lvl = ft_random();
	if (keycode == ONE || keycode == ONE2)
		m->lvl = ft_strdup("levels/lvl1");
	if (keycode == TWO || keycode == TWO2)
		m->lvl = ft_strdup("levels/lvl2");
	if (keycode == THREE || keycode == THREE2)
		m->lvl = ft_strdup("levels/lvl3");
	levels(keycode, m);
	if (keycode == ESC)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(0);
	}
	return (0);
}

void		play(t_ray *m)
{
	int x;
	int y;

	y = SHEIGHT / 3;
	while (++y < SHEIGHT / 3 + 50)
	{
		x = SWIDTH / 3 + 30;
		while (++x < SWIDTH / 3 + 400)
			mlx_pixel_put(m->mlx, m->win, x, y, 0);
	}
	mlx_string_put(m->mlx, m->win, SWIDTH / 2 - 45, SHEIGHT / 3, 0xffff,
			"0 : RANDOM");
	mlx_string_put(m->mlx, m->win, SWIDTH / 2 - 50, SHEIGHT / 3 + 30, 0xffff,
			"1 : LEVEL 1");
	mlx_string_put(m->mlx, m->win, SWIDTH / 2 - 50, SHEIGHT / 3 + 60, 0xffff,
			"2 : LEVEL 2");
	mlx_string_put(m->mlx, m->win, SWIDTH / 2 - 50, SHEIGHT / 3 + 90, 0xffff,
			"3 : LEVEL 3");
	mlx_string_put(m->mlx, m->win, SWIDTH / 2 - 45, SHEIGHT / 3 + 120, 0xffff,
			"R : RETURN");
	mlx_key_hook(m->win, events, m);
	mlx_loop(m->mlx);
}
