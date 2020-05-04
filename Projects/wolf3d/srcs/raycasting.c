/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:10:37 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/08 14:03:42 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	calculs(t_ray *r)
{
	r->camerax = 2 * r->x / (double)r->sw - 1;
	r->rayposx = r->posx;
	r->rayposy = r->posy;
	r->raydirx = r->dirx + r->planex * r->camerax;
	r->raydiry = r->diry + r->planey * r->camerax;
	r->mapx = (int)(r->rayposx);
	r->mapy = (int)(r->rayposy);
	r->walldistx2 = sqrt(1 + pow(r->raydiry, 2) / pow(r->raydirx, 2));
	r->walldisty2 = sqrt(1 + pow(r->raydirx, 2) / pow(r->raydiry, 2));
}

static void	collisions(t_ray *r)
{
	r->hit = 0;
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->walldistx = (r->rayposx - r->mapx) * r->walldistx2;
	}
	else
	{
		r->stepx = 1;
		r->walldistx = (r->mapx + 1.0 - r->rayposx) * r->walldistx2;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->walldisty = (r->rayposy - r->mapy) * r->walldisty2;
	}
	else
	{
		r->stepy = 1;
		r->walldisty = (r->mapy + 1.0 - r->rayposy) * r->walldisty2;
	}
}

static void	dda(t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->walldistx < r->walldisty)
		{
			r->walldistx += r->walldistx2;
			r->mapx += r->stepx;
			r->wall = 0;
		}
		else
		{
			r->walldisty += r->walldisty2;
			r->mapy += r->stepy;
			r->wall = 1;
		}
		if (r->map[r->mapx][r->mapy] > 0)
			r->hit = 1;
		if (r->map[r->mapx][r->mapy] == -1)
			r->hit = -1;
	}
}

static void	calcul_lines(t_ray *r)
{
	double calcul;
	double calcul2;

	calcul = (1 - r->stepx) / 2;
	calcul2 = (1 - r->stepy) / 2;
	if (r->wall == 0)
		r->wall_length = fabs((r->mapx - r->rayposx + calcul) / r->raydirx);
	else
		r->wall_length = fabs((r->mapy - r->rayposy + calcul2) / r->raydiry);
	if (r->wall_length <= 0)
		r->wall_length = 0.000001;
	r->wall_height = abs((int)(r->sh / r->wall_length));
	r->ymin = -r->wall_height / 2 + r->sh / 2;
	if (r->ymin < 0)
		r->ymin = 0;
	r->ymax = r->wall_height / 2 + r->sh / 2;
	r->ymax = (r->ymax >= r->sh) ? (r->sh - 1) : (r->ymax);
}

void		raycasting(t_ray *r)
{
	r->x = 0;
	while (r->x < r->sw)
	{
		calculs(r);
		collisions(r);
		dda(r);
		calcul_lines(r);
		put_line(*r);
		r->x++;
	}
}
