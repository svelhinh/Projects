/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:48:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/02 17:00:41 by svelhinh         ###   ########.fr       */
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
	rt->final_color = (int)rt->color.r * 0x10000 + (int)rt->color.g * 0x100
		+ (int)rt->color.b;
}

static	void	intersection(t_env *rt, int reflection)
{
	int			i;
	// t_vector	reflect;
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
	// if (rt->i2 != -1)
	// {
		// calcul_light(rt, i2, rt->reflect);



		if (reflection < MAXREFLECTION && rt->object[rt->i2].shiny)
		{
			rt->inter = calcul_ptinter(rt->orig_reflect, rt->reflect, rt->t);
		// 	if (!reflection)
		// 		rt->tmp_color = rt->color;
			if (rt->object[rt->i2].name != PLANE)
				n = vecsub(&rt->object[rt->i2].center, &rt->inter);
			else
				n = rt->object[rt->i2].center;
			rt->reflect.x = rt->reflect.x - 2 * n.x * vecdot(&n, &rt->reflect);
			rt->reflect.y = rt->reflect.y - 2 * n.y * vecdot(&n, &rt->reflect);
			rt->reflect.z = rt->reflect.y - 2 * n.z * vecdot(&n, &rt->reflect);
			rt->orig_reflect = rt->inter;
			intersection(rt, reflection + 1);
		// }
		// if (reflection)
		// {
		// 	rt->color.r = rt->color.r * reflection + rt->tmp_color.r * (1 - reflection);
		// 	rt->color.g = rt->color.g * reflection + rt->tmp_color.g * (1 - reflection);
		// 	rt->color.b = rt->color.b * reflection + rt->tmp_color.b * (1 - reflection);
		// 	rt->color.r = (rt->color.r > 0xff) ? (0xff) : (rt->color.r);
		// 	rt->color.g = (rt->color.g > 0xff) ? (0xff) : (rt->color.g);
		// 	rt->color.b = (rt->color.b > 0xff) ? (0xff) : (rt->color.b);
		}
	// }
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
			rt->final_color = 0;
			rt->orig_reflect = rt->eye;
			rt->reflect = ray;
			intersection(rt, 0);
			if (rt->i2 != -1 && rt->object[rt->i2].name != LIGHT)
			{
				rt->inter = calcul_ptinter(rt->orig_reflect, rt->reflect, rt->t);
				calcul_light(rt, rt->i2, rt->reflect);
			}
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