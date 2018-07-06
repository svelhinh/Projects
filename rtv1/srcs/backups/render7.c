/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/15 11:12:46 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		draw(t_rt *rt, char *object, int x, int y)
{
	if (rt->currentobj != -1)
	{
		if (!ft_strcmp("sphere", object))
			mlx_pixel_put_to_image(rt->s[rt->currentobj].color, rt, x, y);
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
	/*float		x2;
	float		y2;
	float		z2;
	float		x3;
	float		y3;
	float		z3;*/
	float		rotx;
	//float		roty;
	//float		rotz;

	z = rt->campos.z;
	y = 0;
	rotx = 0;
	//roty = 0;
	//rotz = 0.05;
	while (y < SH)
	{
		x = 0;
		while (x < SW)
		{
			/*rt->r.dir.y = y * cos(rotx) - z * sin(rotx);
			rt->r.dir.z = y * sin(rotx) + z * cos(rotx);
			rt->r.dir.x = x;*/
			/*x3 = x2 * cos(rotz) - y2 * sin(rotz);
			y3 = x2 * sin(rotz) + y2 * cos(rotz);
			z3 = z2;*/
			/*x2 = x * (cos(rotx) * cos(roty) - sin(rotx) * cos(rotz) * sin(roty)) +
				y * (-cos(rotx) * sin(roty) - sin(rotx) * cos(rotz) * cos(roty)) +
				z * (sin(rotx) * sin(rotz));
			y2 = x * (sin(rotx) * cos(roty) + cos(rotx) * cos(rotz) * sin(roty)) +
				y * (-sin(rotx) * sin(roty) + cos(rotx) * cos(rotz) * cos(roty)) +
				z * (-cos(rotx) * sin(rotz));
			z2 = x * (sin(rotz) * sin(roty)) + y * (sin(rotz) * cos(roty)) +
				z * cos(rotz);*/
			/*x2 = x * cos(rot) - y * sin(rot);
			y2 = x * sin(rot) + y * cos(rot);
			z2 = z;*/
			rt->r.start.x = /*x3 + */x + rt->campos.x;
			rt->r.start.y = /*y3 + */y + rt->campos.y;
			rt->r.start.z = /*z3*/z;
			rt->currentobj = -1;
			object = NULL;
			object = intersect(rt, &rt->currentobj, object);
			draw(rt, object, x, y);
			if (object)
				ft_strdel(&object);
			x++;
		}
		y++;
	}
}
