/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/25 12:15:41 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		mlx_pixel_put_to_img(t_coords *c, int x, int y)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	b = (c->color & 0xFF0000) >> 16;
	g = (c->color & 0xFF00) >> 8;
	r = (c->color & 0xFF);
	c->data[y * c->size_line + x * c->bpp / 8] = r;
	c->data[y * c->size_line + x * c->bpp / 8 + 1] = g;
	c->data[y * c->size_line + x * c->bpp / 8 + 2] = b;
}

void	line_verti(t_coords c, t_env e)
{
	float y;

	y = c.ymin;
	while (y <= c.ymax)
	{
		mlx_pixel_put(e.mlx, e.win, c.x, y, c.color);
		y++;
	}
}
