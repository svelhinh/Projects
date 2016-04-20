/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:08:22 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/20 15:08:24 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		raytracer(t_rt *rt)
{
	int x;
	int y;

	int imax;
	int	i;
	int	i2;
	int	object;

	imax = rt->nbs;

	y = 0;
	while (y < rt->h)
	{
		x = 0;
		while (x < rt->w)
		{
			rt->r.dir.x = x - rt->w / 2 - rt->campos.x;
			rt->r.dir.y = y - rt->h / 2 - rt->campos.y;

			i = 0;
			object = -1;
			while (i < imax)
			{
				if (sphere(&rt->r, &rt->s[i]))
				{
					object = 0;
					i2 = i;
				}
				i++;
			}
			if (object == 0)
				rt->color = rt->s[i2].color.r * 255 * 0x10000 +
							rt->s[i2].color.g * 255 * 0x100 +
							rt->s[i2].color.b * 255;
			else
				rt->color = rt->background_color;
			mlx_pixel_put_to_image(rt->color, rt, x, y);
			x++;
		}
		y++;
	}
}