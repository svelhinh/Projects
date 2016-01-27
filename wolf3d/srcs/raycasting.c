/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:10:37 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/27 11:43:09 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	calculs(t_ray *r)
{
	r->camerax = 2 * r->x / (double)SWIDTH - 1;
	r->rayposx = r->posx;
	r->rayposy = r->posy;
	r->raydirx = r->dirx + r->planex * r->camerax;
	r->raydiry = r->diry + r->planey * r->camerax;
	r->mapx = (int)r->rayposx;
	r->mapy = (int)r->rayposy;
	r->dist2murx = sqrt(1 + pow(r->raydiry, 2) / pow(r->raydirx, 2));
	r->dist2mury = sqrt(1 + pow(r->raydirx, 2) / pow(r->raydiry, 2));
}

static void	collisions(t_ray *r)
{
	r->touche = 0;
	if (r->raydirx < 0)
	{
		r->etapex = -1;
		r->distmurx = (r->rayposx - r->mapx) * r->dist2murx;
	}
	else
	{
		r->etapex = 1;
		r->distmurx = (r->mapx + 1.0 - r->rayposx) * r->dist2murx;
	}
	if (r->raydiry < 0)
	{
		r->etapey = -1;
		r->distmury = (r->rayposy - r->mapy) * r->dist2mury;
	}
	else
	{
		r->etapey = 1;
		r->distmury = (r->mapy + 1.0 - r->rayposy) * r->dist2mury;
	}
}

static void	dda(t_ray *r)
{
	while (r->touche == 0)
	{
		if (r->distmurx < r->distmury)
		{
			r->distmurx += r->dist2murx;
			r->mapx += r->etapex;
			r->mur = 0;
		}
		else
		{
			r->distmury += r->dist2mury;
			r->mapy += r->etapey;
			r->mur = 1;
		}
		if (r->map[r->mapx][r->mapy] == 1)
			r->touche = 1;
		else if (r->map[r->mapx][r->mapy] == 2)
			r->touche = 2;
	}
}

static void	calcul_lines(t_ray *r)
{
	double calcul;
	double calcul2;

	calcul = (1 - r->etapex) / 2;
	calcul2 = (1 - r->etapey) / 2;
	if (r->mur == 0)
		r->longueurmur = fabs((r->mapx - r->rayposx + calcul) / r->raydirx);
	else
		r->longueurmur = fabs((r->mapy - r->rayposy + calcul2) / r->raydiry);
	r->hauteurmur = abs((int)(SHEIGHT / r->longueurmur));
	r->drawstart = -r->hauteurmur / 2 + SHEIGHT / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->hauteurmur / 2 + SHEIGHT / 2;
	if (r->drawend >= SHEIGHT)
		r->drawend = SHEIGHT - 1;
}

void		raycasting(t_ray *r)
{
	r->x = 0;
	while (r->x < SWIDTH)
	{
		calculs(r);
		collisions(r);
		dda(r);
		calcul_lines(r);
		put_line(*r);
		if (r->drawend < 0)
			r->drawend = SHEIGHT;
		put_floor_sky(*r);
		r->x++;
	}
}
