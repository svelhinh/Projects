/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/02 19:13:53 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sphere(t_rt *rt)
{
	float	a;
	float	b;
	float	c;
	float	d;
	float	t;

	a = pow(rt->vdir.x, 2) + pow(rt->vdir.y, 2) + pow(rt->vdir.z, 2);
	b = 2 * (rt->vdir.x * (rt->campos.x - rt->sphere.x) + rt->vdir.y *
			(rt->campos.y - rt->sphere.y) + rt->vdir.z *
			(rt->campos.z - rt->sphere.z));
	c = (pow(rt->campos.x - rt->sphere.x, 2) +
			pow(rt->campos.y - rt->sphere.y, 2) +
			pow(rt->campos.z - rt->sphere.z, 2)) - pow(rt->sphereradius, 2);
	d = pow(b, 2) - 4 * a * c;
	if (d < 0)
		mlx_pixel_put(rt->mlx, rt->win, rt->vdir.x, rt->vdir.y, 0);
	else
	{
		if (d > 0)
			t = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		else if (d == 0)
			t = -b / (2 * a);
		mlx_pixel_put(rt->mlx, rt->win, rt->campos.x + t * rt->vdir.x,
				rt->campos.y + t * rt->vdir.y, 0xffffff);
	}
}

void	render(t_rt *rt)
{
	int x;
	int y;
	int z;

	z = 0;
	rt->campos.x = 0;
	rt->campos.y = 0;
	rt->campos.z = -10;
	rt->sphere.x = 20;
	rt->sphere.y = 20;
	rt->sphere.z = 0;
	rt->sphereradius = 5;
	while (z < 25)
	{
		y = 0;
		while (y < SH)
		{
			x = 0;
			while (x < SW)
			{
				rt->vdir.x = x;
				rt->vdir.y = y;
				rt->vdir.z = z;
				sphere(rt);
				x++;
			}
			y++;
		}
		z++;
	}
}
