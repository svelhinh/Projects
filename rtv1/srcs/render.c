/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/22 12:48:16 by svelhinh         ###   ########.fr       */
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
<<<<<<< HEAD
=======
			rt->pixel_color = 0;
			rt->level = 0;
>>>>>>> 9da8e16bc074a19e2f992c9425955b5289259946
			rt->currentobj = -1;
			rt->global_color.red = 0;
			rt->global_color.blue = 0;
			rt->global_color.green = 0;
			rt->r.start.x = x + rt->campos.x;
			rt->r.start.y = y + rt->campos.y;
<<<<<<< HEAD
			object = intersect(rt, &rt->currentobj, object);
			rt->pixel_color = (int)(rt->global_color.red * 255) * 0x10000 + (int)(rt->global_color.green * 255) * 0x100 + (int)(rt->global_color.blue * 255);
			draw(rt, x, y);
=======
			rt->r.start.z = z;
			object = intersect(rt, &rt->currentobj, object);
			draw(rt, object, x, y);
>>>>>>> 9da8e16bc074a19e2f992c9425955b5289259946
			ft_strdel(&object);
			x++;
		}
		if (y == 0.25 * SH)
				ft_putendl("25% completed !");
		if (y == 0.5 * SH)
			ft_putendl("50% completed !");
		if (y == 0.75 * SH)
			ft_putendl("75% completed !");
		if (y == SH - 1)
			ft_putendl("100% completed !");
		y++;
	}
}
