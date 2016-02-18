/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:54:42 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/18 18:03:24 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sphere(t_rt *rt)
{
	int			x_center;
	int			y_center;
	int			m;
	int			rayon;
	t_coords	c;

	rayon = 300;
	c.color = 0xffffff;
	x_center = SW / 2;
	y_center = SH / 2;
	while (rayon >= 0)
	{
		c.x = 0;
		c.y = rayon;
		m = rayon - 1;
		while (c.y >= c.x)
		{
			mlx_pixel_put_to_image(&c, rt, c.x + x_center, c.y + y_center);
			mlx_pixel_put_to_image(&c, rt, c.y + x_center, c.x + y_center);
			mlx_pixel_put_to_image(&c, rt, -c.x + x_center, c.y + y_center);
			mlx_pixel_put_to_image(&c, rt, -c.y + x_center, c.x + y_center);
			mlx_pixel_put_to_image(&c, rt, c.x + x_center, -c.y + y_center);
			mlx_pixel_put_to_image(&c, rt, c.y + x_center, -c.x + y_center);
			mlx_pixel_put_to_image(&c, rt, -c.x + x_center, -c.y + y_center);
			mlx_pixel_put_to_image(&c, rt, -c.y + x_center, -c.x + y_center);
			if (m >= 2 * c.x)
			{
				m = m - 2 * c.x - 1;
				c.x++;
			}
			else if (m < 2 * (rayon - c.y))
			{
				m = m + 2 * c.y - 1;
				c.y--;
			}
			else
			{
				m = m + 2 * (c.y - c.x - 1);
				c.y--;
				c.x++;
			}
		}
		rayon--;
	}
}
