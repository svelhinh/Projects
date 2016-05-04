/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:48:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/04 18:19:06 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		calcul_light(t_env *rt, int i2, t_vector ray)
{
	int			i;

	i = 0;
	rt->color.r = 0;
	rt->color.g = 0;
	rt->color.b = 0;
	while (i < rt->nblight)
	{
		light(rt, rt->object[i2], rt->light[i], ray);
		i++;
	}
	rt->color.r /= rt->nblight;
	rt->color.g /= rt->nblight;
	rt->color.b /= rt->nblight;
	rt->color.r = (rt->color.r > 0xff) ? (0xff) : (rt->color.r);
	rt->color.g = (rt->color.g > 0xff) ? (0xff) : (rt->color.g);
	rt->color.b = (rt->color.b > 0xff) ? (0xff) : (rt->color.b);
}

static	void	intersection(t_env *rt)
{
	int			i;
	t_vector 	tmp_reflect;
	t_vector	n;

	rt->i2 = -1;
	i = 0;
	rt->t = 200000;
	while (i < rt->nbobj)
	{
		if ((rt->object[i].name == SPHERE && sphere(rt->reflect, rt->object[i], &rt->t,
				rt->orig_reflect)) ||
			(rt->object[i].name == PLANE && plane(rt->reflect, rt->object[i], &rt->t,
				rt->orig_reflect)) ||
			(rt->object[i].name == CYLINDER && cylinder(rt->reflect, rt->object[i],
				&rt->t, rt->orig_reflect)) ||
			(rt->object[i].name == CONE && cone(rt->reflect, rt->object[i], &rt->t,
				rt->orig_reflect)))
			rt->i2 = i;
		i++;
	}
	rt->inter = calcul_ptinter(rt->orig_reflect, rt->reflect, rt->t);
	calcul_light(rt, rt->i2, rt->reflect);
	if (rt->reflection < rt->max_reflect && rt->object[rt->i2].material.shiny && rt->i2 != -1)
	{
		if (!rt->reflection)
		{
			rt->color2 = rt->color;
			rt->first_reflection = rt->object[rt->i2].material.reflection;
		}
		if (rt->object[rt->i2].name != PLANE)
			n = vecsub(&rt->object[rt->i2].center, &rt->inter);
		else
			n = rt->object[rt->i2].center;
		n = normalize(&n);
		tmp_reflect.x = rt->reflect.x;
		tmp_reflect.y = rt->reflect.y;
		tmp_reflect.z = rt->reflect.z;
		rt->reflect.x = -2 * n.x * vecdot(&n, &tmp_reflect) + tmp_reflect.x;
		rt->reflect.y = -2 * n.y * vecdot(&n, &tmp_reflect) + tmp_reflect.y;
		rt->reflect.z = -2 * n.z * vecdot(&n, &tmp_reflect) + tmp_reflect.z;
		rt->orig_reflect = rt->inter;
	}
	rt->color2.r = rt->color.r * rt->first_reflection + rt->color2.r * (1 - rt->first_reflection);
	rt->color2.g = rt->color.g * rt->first_reflection + rt->color2.g * (1 - rt->first_reflection);
	rt->color2.b = rt->color.b * rt->first_reflection + rt->color2.b * (1 - rt->first_reflection);
	if (rt->reflection < rt->max_reflect && rt->object[rt->i2].material.shiny && rt->i2 != -1)
	{
		rt->reflection++;
		rt->reflect = vecscale(&rt->reflect, 1 + 0.001);
		intersection(rt);
	}
}

static void		scan(int pas, t_env *rt)
{
	int			x;
	int			y;
	t_vector	ray;

	y = rt->start_h;
	while (y < rt->end_h)
	{
		x = 0;
		while (x < rt->w)
		{
			ray.x = x - rt->w / 2 - rt->eye.x + rt->xx;
			ray.y = y - rt->h / 2 - rt->eye.y;
			ray.z = rt->w - rt->eye.z + rt->zz;
			ray = rotations(ray, rt->cam_angle.x, rt->cam_angle.y,
				rt->cam_angle.z);
			rt->color2.r = 0;
			rt->color2.g = 0;
			rt->color2.b = 0;
			rt->final_color = 0;
			rt->first_reflection = 1;
			rt->orig_reflect = rt->eye;
			rt->reflect = ray;
			rt->reflect = normalize(&rt->reflect);
			rt->reflection = 0;
			intersection(rt);
			rt->final_color = (int)rt->color2.r * 0x10000 + (int)rt->color2.g * 0x100
				+ (int)rt->color2.b;
			mlx_pixel_put_to_image(rt->final_color, rt, x, y);
			x += pas;
		}
		y += pas;
	}
}

void			*raytracer(void *arg)
{
	int		pas;
	t_env	*rt;

	rt = (t_env *)arg;
	pas = 1;
	if (rt->keyup == 1 || rt->keydown == 1 || rt->keyleft == 1
		|| rt->keyright == 1)
		pas = rt->w / 640 + rt->h / 480;
	scan(pas, rt);
	pthread_exit(0);
}
