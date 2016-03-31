/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/31 11:40:27 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		draw(t_rt *rt, int x, int y)
{
	if (rt->currentobj != -1)
		mlx_pixel_put_to_image(rt->pixel_color, rt, x, y);
	else
		mlx_pixel_put_to_image(rt->background_color, rt, x, y);
}

static void		loading(int y, float h)
{
	if (y == 0.25 * h)
		ft_putendl("25% completed !");
	if (y == 0.5 * h)
		ft_putendl("50% completed !");
	if (y == 0.75 * h)
		ft_putendl("75% completed !");
	if (y == h - 1)
		ft_putendl("100% completed !");
}

static void		init(t_rt *rt, int x, int y)
{
	rt->pixel_color = 0;
	rt->currentobj = -1;
	rt->global_color.red = 0;
	rt->global_color.blue = 0;
	rt->global_color.green = 0;
	rt->r.start.x = x + rt->campos.x;
	rt->r.start.y = y + rt->campos.y;
	if (rt->rotcam.z)
	{
		rt->r.start.x = rt->r.start.x * cos(rt->rotcam.z) - rt->r.start.y * sin(rt->rotcam.z);
		rt->r.start.y = rt->r.start.x * sin(rt->rotcam.z) + rt->r.start.y * cos(rt->rotcam.z);
	}
}

void			render(t_rt *rt)
{
	char		*object;
	int			x;
	int			y;

	y = 0;
	rt->r.start.z = rt->campos.z;
	while (y < rt->h)
	{
		x = 0;
		while (x < rt->w)
		{
			init(rt, x, y);
			object = intersect(rt, &rt->currentobj, object);
			rt->pixel_color = (int)(rt->global_color.red * 255) * 0x10000
				+ (int)(rt->global_color.green * 255) * 0x100
				+ (int)(rt->global_color.blue * 255);
			draw(rt, x, y);
			ft_strdel(&object);
			x++;
		}
		loading(y, rt->h);
		y++;
	}
}
