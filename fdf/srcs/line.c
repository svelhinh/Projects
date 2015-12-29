/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/29 17:16:24 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_xy c, void *mlx, void *win, int nblines)
{
	float len;
	float dx;
	float dy;
	float x;
	float y;
	int i;
	int j;
	int coeff;

	if ((c.xmax - c.xmin) >= (c.ymax - c.ymin))
		len = c.xmax - c.xmin;
	else
		len = c.ymax - c.ymin;
	dx = (c.xmax - c.xmin) / len;
	dy = (c.ymax - c.ymin) / len;
	j = 0;
	x = c.xmin;
	y = c.ymin;
	coeff = 20;
	while (j < nblines)
	{
		i = 0;
		while (i < len)
		{
			mlx_pixel_put(mlx, win, x, y, c.color);
			x += dx;
			y += dy;
			i++;
		}
		j++;
		x = c.xmin + j * coeff;
		y = c.ymin + j * coeff;
	}
	i = 0;
	c.xmax = c.xmin + (coeff * (nblines - 1));
	c.ymax = c.ymin + (coeff * (nblines - 1));
	if ((c.xmax - c.xmin) >= (c.ymax - c.ymin))
		len = c.xmax - c.xmin;
	else
		len = c.ymax - c.ymin;
	dx = (c.xmax - c.xmin) / len;
	dy = (c.ymax - c.ymin) / len;
	j = 0;
	x = c.xmin;
	y = c.ymin;
	while (j < nblines)
	{
		while (i < len)
		{
			mlx_pixel_put(mlx, win, x, y, c.color);
			x += dx;
			y += dy;
			i++;
		}
		j++;
		x = c.xmin + j * coeff;
		//y = c.ymin + j * coeff;
	}
}
