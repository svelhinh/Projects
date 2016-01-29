/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:16:09 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/29 18:35:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			expose(t_ray *r)
{
	r->img = mlx_new_image(r->mlx, SWIDTH, SHEIGHT);
	r->data = mlx_get_data_addr(r->img, &r->bpp, &r->size_line, &r->endian);
	if (r->i == 0)
	{
		init_var(r);
		r->i = 1;
	}
	raycasting(r);
	mlx_put_image_to_window(r->mlx, r->win, r->img, 0, 0);
	mlx_destroy_image(r->mlx, r->img);
	return (0);
}

static void	rotate(int keycode, t_ray *r)
{
	double olddirx;
	double oldplanex;

	if (keycode == 123/*65361*/)
	{
		olddirx = r->dirx;
		r->dirx = r->dirx * cos(ROT) - r->diry * sin(ROT);
		r->diry = olddirx * sin(ROT) + r->diry * cos(ROT);
		oldplanex = r->planex;
		r->planex = r->planex * cos(ROT) - r->planey * sin(ROT);
		r->planey = oldplanex * sin(ROT) + r->planey * cos(ROT);
	}
	if (keycode == 124/*65363*/)
	{
		olddirx = r->dirx;
		r->dirx = r->dirx * cos(-ROT) - r->diry * sin(-ROT);
		r->diry = olddirx * sin(-ROT) + r->diry * cos(-ROT);
		oldplanex = r->planex;
		r->planex = r->planex * cos(-ROT) - r->planey * sin(-ROT);
		r->planey = oldplanex * sin(-ROT) + r->planey * cos(-ROT);
	}
	if (keycode == 123/*65361*/ || keycode == 124/*65363*/)
		expose(r);
}

static void	move(int keycode, t_ray *r)
{
	if (r->map[(int)(r->posx + r->dirx * MOVE)][(int)r->posy] == 2
			|| r->map[(int)r->posx][(int)(r->posy + r->diry * MOVE)] == 2)
		ft_exit("win");
	if (keycode == 125/*65364*/)
	{
		if (!r->map[(int)(r->posx - r->dirx * MOVE)][(int)r->posy])
			r->posx -= r->dirx * MOVE;
		if (!r->map[(int)r->posx][(int)(r->posy - r->diry * MOVE)])
			r->posy -= r->diry * MOVE;
		if (!r->map[(int)(r->posx - r->dirx * MOVE)][(int)r->posy]
				|| !r->map[(int)r->posx][(int)(r->posy - r->diry * MOVE)])
			expose(r);
	}
	if (keycode == 126/*65362*/)
	{
		if (!r->map[(int)(r->posx + r->dirx * MOVE)][(int)r->posy])
			r->posx += r->dirx * MOVE;
		if (!r->map[(int)r->posx][(int)(r->posy + r->diry * MOVE)])
			r->posy += r->diry * MOVE;
		if (!r->map[(int)(r->posx + r->dirx * MOVE)][(int)r->posy]
				|| !r->map[(int)r->posx][(int)(r->posy + r->diry * MOVE)])
			expose(r);
	}
}

int			key(int keycode, t_ray *r)
{
	move(keycode, r);
	rotate(keycode, r);
	if (keycode == 53/*65307*/)
		exit(0);
	return (0);
}
