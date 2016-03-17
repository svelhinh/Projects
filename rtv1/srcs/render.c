/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/17 16:40:42 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		draw(t_rt *rt, char *object, int x, int y)
{
	if (rt->currentobj != -1)
	{
		if (!ft_strcmp("sphere", object))
			mlx_pixel_put_to_image(rt->/*s[rt->currentobj].color*/pixel_color, rt, x, y);
		else if (!ft_strcmp("plane", object))
			mlx_pixel_put_to_image(rt->p[rt->currentobj].color, rt, x, y);
		else if (!ft_strcmp("cylinder", object))
			mlx_pixel_put_to_image(rt->c[rt->currentobj].color, rt, x, y);
		else if (!ft_strcmp("cone", object))
			mlx_pixel_put_to_image(rt->co[rt->currentobj].color, rt, x, y);
	}
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
			draw(rt, object, x, y);
			ft_strdel(&object);
			x++;
		}
		y++;
	}
}
