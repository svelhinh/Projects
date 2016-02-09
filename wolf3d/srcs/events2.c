/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:16:09 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/09 14:13:22 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	victory(int keycode, t_ray *r)
{
	if (keycode == R)
	{
		r->forward = 0;
		r->back = 0;
		r->leftrot = 0;
		r->rightrot = 0;
		r->v = 0;
		r->m = 0;
		main2(*r);
	}
	else if (keycode == ESC)
	{
		mlx_destroy_window(r->mlx, r->win);
		exit(0);
	}
}

void	event_pause(int keycode, t_ray *r)
{
	if (keycode == R)
	{
		r->p = 0;
		main2(*r);
	}
	if (keycode == M)
	{
		r->v = 1;
		r->forward = 0;
		r->back = 0;
		r->leftrot = 0;
		r->rightrot = 0;
	}
}
