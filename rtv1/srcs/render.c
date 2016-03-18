/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/18 11:50:07 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		draw(t_rt *rt, int x, int y)
{
	if (rt->currentobj != -1)
		mlx_pixel_put_to_image(rt->pixel_color, rt, x, y);
	else
		mlx_pixel_put_to_image(rt->default_color, rt, x, y);
}

void			render(t_rt *rt)
{
	char		*object;
	int			x;
	int			y;

	y = 0;
	rt->r.start.z = rt->campos.z;
	while (y < SH)
	{
		x = 0;
		while (x < SW)
		{
			rt->currentobj = -1;
			rt->global_color.red = 0;
			rt->global_color.blue = 0;
			rt->global_color.green = 0;
			rt->r.start.x = x + rt->campos.x;
			rt->r.start.y = y + rt->campos.y;
			object = intersect(rt, &rt->currentobj, object);
			rt->pixel_color = (int)(rt->global_color.red * 255) * 0x10000 + (int)(rt->global_color.green * 255) * 0x100 + (int)(rt->global_color.blue * 255);
			draw(rt, x, y);
			ft_strdel(&object);
			x++;
		}
		y++;
	}
}
