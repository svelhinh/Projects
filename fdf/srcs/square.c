/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:35:47 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/28 10:52:17 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xline(t_xy c, void *mlx, void *win)
{
	while (c.xmin < c.xmax)
	{
		mlx_pixel_put(mlx, win, c.xmin, c.y, c.color);
		c.xmin++;
	}
}

void	yline(t_xy c, void *mlx, void *win)
{
	while (c.ymin < c.ymax)
	{
		mlx_pixel_put(mlx, win, c.x, c.ymin, c.color);
		c.ymin++;
	}
}
