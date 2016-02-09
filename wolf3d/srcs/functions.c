/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 11:29:30 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/09 14:01:01 by svelhinh         ###   ########.fr       */
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

static int	victory(int keycode, t_ray *v)
{
	if (keycode == ENTER)
	{
		v->forward = 0;
		v->back = 0;
		v->leftrot = 0;
		v->rightrot = 0;
		v->v = 0;
		principal_menu(v, 2);
	}
	return (0);
}

void		ft_win(t_ray *r)
{
	r->m = 1;
	mlx_string_put(r->mlx, r->win, r->sw / 2 - 35, r->sh / 2, 0xff00, "YOU WIN");
	mlx_string_put(r->mlx, r->win, r->sw / 2 - 155, r->sh / 2 + 30, 0xf0f000,
			"PRESS ENTER TO GO BACK TO MENU");
	mlx_string_put(r->mlx, r->win, r->sw / 2 - 140, r->sh / 2 + 50, 0xf0f000,
			"PRESS R TO RETRY THIS LEVEL");
	mlx_key_hook(r->win, victory, r);
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
		y = 0;
		while (++y < m->sh)
		{
			x = 0;
			while (++x < m->sw)
				mlx_pixel_put(m->mlx, m->win, x, y, 0);
		}
	}
}
