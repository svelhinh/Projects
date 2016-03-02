/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/02 20:09:09 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sphere(t_rt *rt)
{
	float	a;
	float	b;
	float	c;
	float	d;

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
		mlx_pixel_put(rt->mlx, rt->win, rt->vdir.x, rt->vdir.y, 0xffffff);
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
	rt->sphere.x = SW / 2;
	rt->sphere.y = SH / 2;
	rt->sphere.z = 75;
	rt->sphereradius = 50;
	while (z < 50)
	{
		y = 0;
		while (y < SH)
		{
			x = 0;
			while (x < SW)
			{
				rt->vdir.x = x - rt->campos.x;
				rt->vdir.y = y - rt->campos.y;
				rt->vdir.z = z - rt->campos.z;
				sphere(rt);
				x++;
			}
			y++;
		}
		z++;
	}
}
