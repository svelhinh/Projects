/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:48:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/25 18:27:27 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static	void	intersection(t_env *rt, t_vector *ray)
{
	int			i;
	int			i2;

	i2 = -1;
	i = 0;
	rt->color = rt->bg_color;
	while (i < rt->nbobj)
	{
		if ((rt->object[i].name == SPHERE && sphere(ray, &rt->object[i], &rt->t, rt->eye)) ||
			(rt->object[i].name == PLANE && plane(ray, &rt->object[i], &rt->t, rt->eye)) ||
			(rt->object[i].name == CYLINDER && cylinder(ray, &rt->object[i], &rt->t, rt->eye)) ||
			(rt->object[i].name == CONE && cone(ray, &rt->object[i], &rt->t, rt->eye)))
				i2 = i;
		i++;
	}
	if (i2 != -1)
		rt->color = (int)(rt->object[i2].color.r * 255) * 0x10000 +
					(int)(rt->object[i2].color.g * 255) * 0x100 +
					(int)(rt->object[i2].color.b * 255);
}

void		raytracer(t_env *rt)
{
	int			x;
	int			y;
	int			pas;
	t_vector	ray;

	y = 0;
	ray.z = rt->w - rt->eye.z;
	pas = 1;
	// printf("%d\n", rt->object[0].name);
	if (rt->keyup == 1 || rt->keydown == 1 || rt->keyleft == 1 || rt->keyright == 1)
		pas = rt->w / 640 + rt->h / 480;
	while (y < rt->h)
	{
		x = 0;
		while (x < rt->w)
		{
			ray.x = x - (rt->w / 2 - rt->eye.x);
			ray.y = y - (rt->h / 2 - rt->eye.y);
			rt->t = 200000;
			intersection(rt, &ray);
			mlx_pixel_put_to_image(rt->color, rt, x, y);
			x += pas;
		}
		y += pas;
	}
}
