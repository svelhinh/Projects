/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:48:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/29 18:53:42 by svelhinh         ###   ########.fr       */
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
	// if (recursion)
	// {
	// 	rt->tmp_color.r = rt->tmp_color.r * recursion + rt->color.r * (1 - recursion);
	// 	rt->tmp_color.g = rt->tmp_color.g * recursion + rt->color.g * (1 - recursion);
	// 	rt->tmp_color.b = rt->tmp_color.b * recursion + rt->color.b * (1 - recursion);
	// }
	// else
	// {
	// 	rt->tmp_color.r = rt->color.r;
	// 	rt->tmp_color.g = rt->color.g;
	// 	rt->tmp_color.b = rt->color.b;
	// }
	// rt->final_color += (int)rt->tmp_color.r * 0x10000 + (int)rt->tmp_color.g * 0x100
	// 	+ (int)rt->tmp_color.b;
}

static	void	intersection(t_env *rt, t_vector ray, int recursion)
{
	int			i;
	int			i2;
	t_vector	reflect;
	t_vector	n;

	i2 = -1;
	i = 0;
	rt->t = 200000;
	while (i < rt->nbobj)
	{
		if ((rt->object[i].name == SPHERE && sphere(ray, rt->object[i], &rt->t,
				rt->eye)) ||
			(rt->object[i].name == PLANE && plane(ray, rt->object[i], &rt->t,
				rt->eye)) ||
			(rt->object[i].name == CYLINDER && cylinder(ray, rt->object[i],
				&rt->t, rt->eye)) ||
			(rt->object[i].name == CONE && cone(ray, rt->object[i], &rt->t,
				rt->eye)))
			i2 = i;
		i++;
	}
	if (i2 != -1)
	{
		rt->inter = calcul_ptinter(rt->eye, ray, rt->t);
		calcul_light(rt, i2, ray);
		if (recursion < MAXRECURSION)
		{
			if (!recursion)
			{
				rt->tmp_color.r = rt->color.r;
				rt->tmp_color.g = rt->color.g;
				rt->tmp_color.b = rt->color.b;
			}
			if (rt->object[i2].shiny)
			{
				n = vecsub(&rt->object[i2].center, &rt->inter);
				reflect.x = -2 * n.x * vecdot(&n, &ray) + ray.x;
				reflect.y = -2 * n.y * vecdot(&n, &ray) + ray.y;
				reflect.z = -2 * n.z * vecdot(&n, &ray) + ray.z;
				intersection(rt, reflect, recursion + 1);
			}
		}
		if (recursion)
		{
			rt->color.r = rt->color.r * recursion + rt->tmp_color.r * (1 - recursion);
			rt->color.g = rt->color.g * recursion + rt->tmp_color.g * (1 - recursion);
			rt->color.b = rt->color.b * recursion + rt->tmp_color.b * (1 - recursion);
		}
		rt->final_color = (int)rt->color.r * 0x10000 + (int)rt->color.g * 0x100
			+ (int)rt->color.b;
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
			rt->final_color = 0;
			intersection(rt, ray, 0);
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
