/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:16:09 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/10 13:50:58 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	move(t_ray *r)
{
	if (r->p && r->v)
	{
		r->v = 0;
		r->p = 0;
		principal_menu(r, 2);
	}
	if (r->p)
		ft_pause(r);
	if (r->v)
		ft_win(r);
	else if (!r->p)
	{
		if (r->forward == 1)
			move_forward(r);
		if (r->back == 1)
			move_back(r);
		if (r->leftrot == 1)
			rotate_left(r);
		if (r->rightrot == 1)
			rotate_right(r);
	}
}

int			expose(t_ray *r)
{
	r->img = mlx_new_image(r->mlx, r->sw, r->sh);
	r->data = mlx_get_data_addr(r->img, &r->bpp, &r->size_line, &r->endian);
	if (r->i == 0)
	{
		init_var(r);
		r->i = 1;
	}
	raycasting(r);
	mlx_put_image_to_window(r->mlx, r->win, r->img, 0, 0);
	mlx_destroy_image(r->mlx, r->img);
	move(r);
	if (r->map[(int)(r->posx + r->dirx * MOVE)][(int)r->posy] == -1
			|| r->map[(int)r->posx][(int)(r->posy + r->diry * MOVE)] == -1
			|| r->map[(int)(r->posx - r->dirx * MOVE)][(int)r->posy] == -1
			|| r->map[(int)r->posx][(int)(r->posy - r->diry * MOVE)] == -1)
	{
		r->time = clock() - r->time - r->time_s;
		r->v = 1;
	}
	return (0);
}

int			key_press(int keycode, t_ray *r)
{
	if (r->v)
		victory(keycode, r);
	if (r->m)
		return (0);
	if (keycode == P)
	{
		r->p ^= 1;
		event_pause2(r);
	}
	else if (keycode == ESC)
	{
		mlx_destroy_window(r->mlx, r->win);
		exit(0);
	}
	(r->p) ? (event_pause(keycode, r)) : (0);
	(keycode == R) ? (main2(*r)) : (0);
	if (keycode == W || keycode == UP)
		r->forward = 1;
	else if (keycode == S || keycode == DOWN)
		r->back = 1;
	else if (keycode == A || keycode == LEFT)
		r->leftrot = 1;
	else if (keycode == D || keycode == RIGHT)
		r->rightrot = 1;
	return (0);
}

int			key_release(int keycode, t_ray *r)
{
	if (keycode == W || keycode == UP)
		r->forward = 0;
	else if (keycode == S || keycode == DOWN)
		r->back = 0;
	else if (keycode == A || keycode == LEFT)
		r->leftrot = 0;
	else if (keycode == D || keycode == RIGHT)
		r->rightrot = 0;
	return (0);
}
