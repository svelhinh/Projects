/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:41:07 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/20 17:21:57 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	illuminati_init(t_fract *e)
{
	e->fractx = (e->x2 - e->x1) * e->zoom;
	e->fracty = (e->y2 - e->y1) * e->zoom;
}

void		illuminati(t_fract e)
{
	illuminati_init(&e);
	while (e.y < HEIGHT)
	{
		e.x = 0;
		while (e.x < WIDTH)
		{
			e.z = 0;
			e.c = (e.x / e.zoom + e.x1) + (e.y / e.zoom + e.y1) * _Complex_I;
			e.i = 0;
			while (creal(e.z) * creal(e.z) + cimag(e.z) * cimag(e.z) < 4
					&& e.i < e.i_max)
			{
				e.z = 1 / (cpow(e.z, 2) + e.c);
				e.i++;
			}
			if (e.i == e.i_max)
				e.color = 0x0;
			else
				e.color = 0x424242 * (e.i * 255 / e.i_max_base);
			mlx_pixel_put_to_image(&e);
			e.x++;
		}
		e.y++;
	}
}
