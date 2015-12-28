/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/28 18:22:02 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_xy c, void *mlx, void *win)
{
	float	dx;
	float	dy;
	int		x;
	int		y;
	float	e1;
	float	e[2] = {0, 1};

	x = c.xmin;
	y = c.ymin;
	dx = c.xmax - c.xmin;
	dy = c.ymax - c.ymin;
	e1 = -0.5;
	e[0] = dy / dx;
	e[1] = -1.0;
	while (x < c.xmax)
	{
		mlx_pixel_put(mlx, win, x, y, c.color);
		if ((e1 = e1 + e[0]) >= 0)
		{
			y++;
			e1 += e[1];
		}
		x++;
	}
}
