/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 11:04:31 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/05 12:52:33 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_forward(t_ray *r)
{
	if (!r->map[(int)(r->posx + r->dirx * MOVE)][(int)r->posy])
		r->posx += r->dirx * MOVE;
	if (!r->map[(int)r->posx][(int)(r->posy + r->diry * MOVE)])
		r->posy += r->diry * MOVE;
}

void	move_back(t_ray *r)
{
	if (!r->map[(int)(r->posx - r->dirx * MOVE)][(int)r->posy])
		r->posx -= r->dirx * MOVE;
	if (!r->map[(int)r->posx][(int)(r->posy - r->diry * MOVE)])
		r->posy -= r->diry * MOVE;
}

void	rotate_left(t_ray *r)
{
	double olddirx;
	double oldplanex;

	olddirx = r->dirx;
	r->dirx = r->dirx * cos(ROT) - r->diry * sin(ROT);
	r->diry = olddirx * sin(ROT) + r->diry * cos(ROT);
	oldplanex = r->planex;
	r->planex = r->planex * cos(ROT) - r->planey * sin(ROT);
	r->planey = oldplanex * sin(ROT) + r->planey * cos(ROT);
}

void	rotate_right(t_ray *r)
{
	double olddirx;
	double oldplanex;

	olddirx = r->dirx;
	r->dirx = r->dirx * cos(-ROT) - r->diry * sin(-ROT);
	r->diry = olddirx * sin(-ROT) + r->diry * cos(-ROT);
	oldplanex = r->planex;
	r->planex = r->planex * cos(-ROT) - r->planey * sin(-ROT);
	r->planey = oldplanex * sin(-ROT) + r->planey * cos(-ROT);
}
