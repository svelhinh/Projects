/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/27 11:45:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			mlx_pixel_put_to_img(t_coords *c, t_ray *v, int x, int y)
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

static void		display(t_coords c, t_ray r)
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

	if (r.mur == 0 && r.raydirx > 0)
		c.color = 0x253C95;
	if (r.mur == 0 && r.raydirx < 0)
		c.color = 0x31A73;
	if (r.mur == 1 && r.raydiry > 0)
		c.color = 0x10851;
	if (r.mur == 1 && r.raydiry < 0)
		c.color = 0x630;
	if (r.touche == 2)
		c.color = 0x1DD029;
	c.x = r.x;
	c.ymin = r.drawstart;
	c.ymax = r.drawend;
	display(c, r);
}

void			put_floor_sky(t_ray r)
{
	t_coords	c;
	int			y;

	y = r.drawend;
	while (y < SHEIGHT)
	{
		c.color = FLOORCOLOR;
		mlx_pixel_put_to_img(&c, &r, c.x, y);
		c.color = SKYCOLOR;
		mlx_pixel_put_to_img(&c, &r, c.x, SHEIGHT - y - 1);
		y++;
	}
}
