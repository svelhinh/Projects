/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:22:14 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/25 12:29:47 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycasting(t_env e)
{
	t_ray		r;
	t_coords	c;

	r.jposX = 2;
	r.jposY = 2;
	r.dirX = 0;
	r.dirY = -1;
	r.planeX = 0;
	r.planeY = 0.66;
	r.x = 0;
	r.hit = 0;
	c.color = 0xff0000;
	while (r.x < SWIDTH)
	{
		r.cameraX = 2 * r.x / SWIDTH - 1;
		r.rposX = r.jposX;
		r.rposY = r.jposY;
		r.rdirX = r.dirX + r.planeX * r.cameraX;
		r.rdirY = r.dirY + r.planeY * r.cameraX;
		r.mapX = r.rposX;
		r.mapY = r.rposY;
		r.deltaDistX = sqrt(1 + pow(r.rdirY, 2) / pow(r.rdirX, 2));
		r.deltaDistY = sqrt(1 + pow(r.rdirX, 2) / pow(r.rdirY, 2));
		if (r.rdirX < 0)
		{
			r.stepX = 1;
			r.sideDistX = (r.rposX - r.mapX) * r.deltaDistX;
		}
		else
		{
			r.stepX = -1;
			r.sideDistX = (r.mapX + 1 - r.rposX) * r.deltaDistX;
		}
		if (r.rdirY < 0)
		{
			r.stepY = -1;
			r.sideDistY = (r.rposY - r.mapY) * r.deltaDistY;
		}
		else
		{
			r.stepY = 1;
			r.sideDistY = (r.mapY + 1 - r.rposY) * r.deltaDistY;
		}
		while (r.hit == 0)
		{
			if (r.sideDistX < r.sideDistY)
			{
				r.sideDistX += r.deltaDistX;
				r.mapX += r.stepX;
				r.side = 0;
			}
			else
			{
				r.sideDistY += r.deltaDistY;
				r.mapY += r.stepY;
				r.side = 1;
			}
			if (e.map[r.mapX][r.mapY] > 0)
				r.hit = 1;
		}
		if (r.side == 0)
			r.wallDist = fabs((r.mapX - r.rposX + (1 - r.stepX) / 2) / r.rdirX);
		else
			r.wallDist = fabs((r.mapY - r.rposY + (1 - r.stepY) / 2) / r.rdirY);
		r.lineHeight = abs((int)(SHEIGHT / r.wallDist));
		r.drawStart = -r.lineHeight / 2 + SHEIGHT / 2;
		r.drawEnd = r.lineHeight / 2 + SHEIGHT / 2;
		if (r.drawStart < 0)
			r.drawStart = 0;
		if (r.drawEnd >= SHEIGHT)
			r.drawEnd = SHEIGHT - 1;
		if (r.side == 1)
			c.color /= 2;
		c.x = r.x;
		c.ymin = r.drawStart;
		c.ymax = r.drawEnd;
		line_verti(c, e);
		r.x++;
	}
}
