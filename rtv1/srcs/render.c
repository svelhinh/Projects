/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/16 16:35:34 by svelhinh         ###   ########.fr       */
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
	float		x;
	float		y;
	float		z;

	z = rt->campos.z;
	y = 0;
	while (y < SH)
	{
		x = 0;
		while (x < SW)
		{
			rt->pixel_color = 0;
			rt->level = 0;
			rt->coef = 1;
			rt->currentobj = -1;
			rt->r.start.x = x + rt->campos.x;
			rt->r.start.y = y + rt->campos.y;
			rt->r.start.z = z;
			while (rt->coef > 0 && rt->level < 15)
			{
				object = intersect(rt, &rt->currentobj, object);
				if (rt->currentobj == -1)
					break ;
				rt->level++;
			}
			draw(rt, object, x, y);
			ft_strdel(&object);
			x++;
		}
		y++;
	}
}
