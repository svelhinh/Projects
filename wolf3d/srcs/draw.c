/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/08 14:02:34 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		mlx_pixel_put_to_img(t_coords *c, t_ray *v, int x, int y)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	if (!v->endian)
	{
		b = (c->color & 0xFF0000) >> 16;
		r = (c->color & 0xFF);
	}
	else
	{
		r = (c->color & 0xFF0000) >> 16;
		b = (c->color & 0xFF);
	}
	g = (c->color & 0xFF00) >> 8;
	v->data[y * v->size_line + x * v->bpp / 8] = r;
	v->data[y * v->size_line + x * v->bpp / 8 + 1] = g;
	v->data[y * v->size_line + x * v->bpp / 8 + 2] = b;
}

static void		draw_floor_sky(t_ray r)
{
	int			y;
	int			check_board;
	t_coords	c;

	y = r.ymax;
	while (y < r.sh)
	{
		r.cdist = r.sh / (2.0 * y - r.sh);
		r.weight = (r.cdist - r.distplayer) / (r.distwall - r.distplayer);
		r.cfloorx = r.weight * r.fwallx + (1.0 - r.weight) * r.posx;
		r.cfloory = r.weight * r.fwally + (1.0 - r.weight) * r.posy;
		r.ftexx = (int)(r.cfloorx * r.w) % r.w;
		r.ftexy = (int)(r.cfloory * r.h) % r.h;
		check_board = ((int)r.cfloorx * (int)r.cfloory) % 5;
		c.color = (r.nb_lvl == 2) ? (r.texture[4][r.w * r.ftexy + r.ftexx]) :
			((r.texture[0][r.w * r.ftexy + r.ftexx] >> 1) & 8355711);
		//c.color = CFLOOR;
		mlx_pixel_put_to_img(&c, &r, r.x, y);
		c.color = (r.nb_lvl == 2) ? (CSKY) :
			(r.texture[0][r.w * r.ftexy + r.ftexx]);
		//printf("x : %d - y : %d\n", r.x, r.sh - y - 1);
		mlx_pixel_put_to_img(&c, &r, r.x, r.sh - y - 1);
		y++;
	}
}

static void		put_floor_sky(t_ray r)
{
	r.distwall = r.wall_length;
	r.distplayer = 0;
	r.cdist = 0;
	if (r.wall == 0 && r.raydirx > 0)
	{
		r.fwallx = r.mapx;
		r.fwally = r.mapy + r.wallx;
	}
	else if (r.wall == 0 && r.raydirx < 0)
	{
		r.fwallx = r.mapx + 1.0;
		r.fwally = r.mapy + r.wallx;
	}
	else if (r.wall == 1 && r.raydiry > 0)
	{
		r.fwallx = r.mapx + r.wallx;
		r.fwally = r.mapy;
	}
	else
	{
		r.fwallx = r.mapx + r.wallx;
		r.fwally = r.mapy + 1.0;
	}
	draw_floor_sky(r);
}

static void		draw(t_coords c, t_ray r)
{
	int y;
	int d;
	int tex;

	tex = r.map[r.mapx][r.mapy] - 1;
	y = c.ymin;
	while (y < c.ymax)
	{
		d = y * 256 - r.sh * 128 + r.wall_height * 128;
		r.texy = ((d * r.h) / r.wall_height) / 256;
		if (r.hit >= 0)
			c.color = r.texture[tex][r.h * r.texy + r.texx];
		(r.wall == 1) ? (c.color = (c.color >> 1) & 8355711) : (0);
		(r.hit == -1) ? (c.color = r.texture[5][r.h * r.texy + r.texx]) : (0);
		mlx_pixel_put_to_img(&c, &r, c.x, y);
		y++;
	}
}

void			put_line(t_ray r)
{
	t_coords c;

	if (r.wall == 1)
		r.wallx = r.rayposx + ((r.mapy - r.rayposy + (1 - r.stepy) / 2)
				/ r.raydiry) * r.raydirx;
	else
		r.wallx = r.rayposy + ((r.mapx - r.rayposx + (1 - r.stepx) / 2)
				/ r.raydirx) * r.raydiry;
	r.wallx -= floor(r.wallx);
	r.texx = (int)(r.wallx * (double)r.w);
	(r.wall == 0 && r.raydirx > 0) ? (r.texx = r.w - r.texx - 1) : (0);
	(r.wall == 1 && r.raydiry < 0) ? (r.texx = r.w - r.texx - 1) : (0);
	c.ymin = r.ymin;
	c.ymax = r.ymax;
	c.x = r.x;
	draw(c, r);
	put_floor_sky(r);
}
