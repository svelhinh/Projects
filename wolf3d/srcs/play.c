/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:59:30 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/08 18:55:47 by svelhinh         ###   ########.fr       */
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
	nb_alea++;
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
		main2(*m);
}

static int	events(int keycode, t_ray *m)
{
	if (keycode == R)
		principal_menu(m, 1);
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

	y = m->sh / 2;
	while (++y < m->sh / 2 + 90)
	{
		x = m->sw / 2 - 55;
		while (++x < m->sw / 2 + 60)
			mlx_pixel_put(m->mlx, m->win, x, y, 0);
	}
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 50, m->sh / 2, 0xffff,
			"0 : RANDOM");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 55, m->sh / 2 + 30, 0xffff,
			"1 : LEVEL 1");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 55, m->sh / 2 + 60, 0xffff,
			"2 : LEVEL 2");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 55, m->sh / 2 + 90, 0xffff,
			"3 : LEVEL 3");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 50, m->sh / 2 + 120, 0xffff,
			"R : RETURN");
	mlx_key_hook(m->win, events, m);
	mlx_loop(m->mlx);
}
