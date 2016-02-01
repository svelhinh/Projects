/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/01 18:47:45 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		mlx_pixel_put_to_img(t_coords *c, t_ray *v, int x, int y)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	b = (c->color & 0xFF0000) >> 16;
	g = (c->color & 0xFF00) >> 8;
	r = (c->color & 0xFF);
	v->data[y * v->size_line + x * v->bpp / 8] = r;
	v->data[y * v->size_line + x * v->bpp / 8 + 1] = g;
	v->data[y * v->size_line + x * v->bpp / 8 + 2] = b;
}

void			put_floor_sky(t_ray r)
{
	t_coords	c;
	int			y;

	(r.ymax < 0) ? (r.ymax = SHEIGHT) : (0);
	y = r.ymax;
	while (y < SHEIGHT)
	{
		c.color = FLOOR;
		mlx_pixel_put_to_img(&c, &r, c.x, y);
		c.color = SKY;
		mlx_pixel_put_to_img(&c, &r, c.x, SHEIGHT - y - 1);
		y++;
	}
}

static void		display(t_coords c, t_ray r)
{
	int y;
	int d;
	int tex;

	tex = r.map[r.mapx][r.mapy] - 1;
	y = c.ymin;
	while (y < c.ymax)
	{
		d = y * 256 - SHEIGHT * 128 + r.wall_height * 128;
		r.texy = ((d * r.h) / r.wall_height) / 256;
		if (r.hit >= 0)
			c.color = r.texture[tex][r.h * r.texy + r.texx];
		(r.wall == 1) ? (c.color = (c.color >> 1) & 8355711) : (0);
		(r.hit == -1) ? (c.color = 0x00) : (0);
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
	display(c, r);
}
