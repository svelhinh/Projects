/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 11:29:30 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/08 16:34:38 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_swap(double *a, double *b)
{
	double c;

	c = *a;
	*a = *b;
	*b = c;
}

void		init_var(t_ray *r)
{
	if (r->nb_lvl == 0)
	{
		r->posx = 19;
		r->posy = 11;
	}
	if (r->nb_lvl == 1)
	{
		r->posx = 31;
		r->posy = 28;
	}
	if (r->nb_lvl == 2)
	{
		r->posx = 38;
		r->posy = 11;
	}
	r->dirx = -1;
	r->diry = 0;
	r->planex = 0;
	r->planey = 0.66;
}

static int	win(int keycode, t_ray *m)
{
	if (keycode == ENTER)
	{
		m->forward = 0;
		m->back = 0;
		m->leftrot = 0;
		m->rightrot = 0;
		principal_menu(m, 2);
	}
	return (0);
}

void		ft_win(t_ray *r)
{
	mlx_string_put(r->mlx, r->win, r->sw / 2, r->sh / 2, 0xff00, "YOU WIN");
	mlx_string_put(r->mlx, r->win, r->sw / 2 - 120, r->sh / 2 + 20, 0xf0f000,
			"PRESS ENTER TO GO BACK TO MENU");
	mlx_key_hook(r->win, win, r);
	mlx_loop(r->mlx);
}

void		ft_empty(t_ray *m, int i)
{
	int x;
	int y;

	if (i == 1)
	{
		y = m->sh / 2 - 100;
		while (++y < m->sh / 2 + 200)
		{
			x = m->sw / 2 - 100;
			while (++x < m->sw / 2 + 100)
				mlx_pixel_put(m->mlx, m->win, x, y, 0);
		}
	}
	else
	{
		y = -1;
		while (++y < m->sh)
		{
			x = -1;
			while (++x < m->sw)
				mlx_pixel_put(m->mlx, m->win, x, y, 0);
		}
	}
}
