/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/29 18:46:56 by svelhinh         ###   ########.fr       */
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

/*  static void		display(t_coords c, t_ray r)
	{
	int y;

	y = c.ymin;
	while (y < c.ymax)
	{
	mlx_pixel_put_to_img(&c, &r, c.x, y);
	y++;
	}
	}

	void			put_line(t_ray r)
	{
	t_coords c;

	(r.wall == 0 && r.raydirx > 0) ? (c.color = BACK) : (0);
	(r.wall == 0 && r.raydirx < 0) ? (c.color = FRONT) : (0);
	(r.wall == 1 && r.raydiry > 0) ? (c.color = RIGHT) : (0);
	(r.wall == 1 && r.raydiry < 0) ? (c.color = LEFT) : (0);
	(r.hit == 2) ? (c.color = 0x0) : (0);
	c.x = r.x;
	c.ymin = r.ymin;
	c.ymax = r.ymax;
	display(c, r);
	}*/

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

	y = c.ymin;
	while (y < c.ymax)
	{
		d = y * 256 - SHEIGHT * 128 + r.wall_height * 128;
		r.texy = ((d * THEIGHT) / r.wall_height) / 256;
		c.color = r.texture[THEIGHT * r.texy + r.texx];
		(r.wall == 1) ? (c.color = (c.color >> 1) & 8355711) : (0);
		mlx_pixel_put_to_img(&c, &r, c.x, y);
		y++;
	}
}

void			put_line(t_ray r)
{
	t_coords c;

	if (r.wall == 1)
		r.wallx = r.rayposx + ((r.mapy - r.rayposy + (1 - r.stepy) / 2) / r.raydiry) * r.raydirx;
	else
		r.wallx = r.rayposy + ((r.mapx - r.rayposx + (1 - r.stepx) / 2) / r.raydirx) * r.raydiry;
	r.wallx -= floor(r.wallx);
	r.texx = (int)(r.wallx * (double)TWIDTH);
	if(r.wall == 0 && r.raydirx > 0)
		r.texx = TWIDTH - r.texx - 1;
	if(r.wall == 1 && r.raydiry < 0)
		r.texx = TWIDTH - r.texx - 1;
	c.ymin = r.ymin;
	c.ymax = r.ymax;
	c.x = r.x;
	display(c, r);
}
