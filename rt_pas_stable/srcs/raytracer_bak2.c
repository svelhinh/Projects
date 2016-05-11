/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:48:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/09 14:52:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		calcul_light(t_env *rt, int i2, t_vector ray)
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

int		intersection(t_env *rt, t_vector ray, t_vector origin)
{
	int			i;
	int			i2;

	i2 = -1;
	i = 0;
	rt->t = 200000;
	while (i < rt->nbobj)
	{
		if ((rt->object[i].name == SPHERE && sphere(ray, rt->object[i], &rt->t,
				origin)) ||
			(rt->object[i].name == PLANE && plane(ray, rt->object[i], &rt->t,
				origin)) ||
			(rt->object[i].name == CYLINDER && cylinder(ray, rt->object[i],
				&rt->t, origin)) ||
			(rt->object[i].name == CONE && cone(ray, rt->object[i], &rt->t,
				origin)))
			i2 = i;
		i++;
	}
	return (i2);
}

static void		scan(int pas, t_env *rt)
{
	int			x;
	int			y;
	int			i2;
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
			ray = normalize(&ray);
			i2 = intersection(rt, ray, rt->eye);
			if (i2 != -1)
			{
				rt->inter = calcul_ptinter(rt->eye, ray, rt->t);
				calcul_light(rt, i2, ray);
				rt->color2 = rt->color;
				rt->first_reflec = rt->object[i2].material.reflection;
				rt->first_refrac = rt->object[i2].material.refraction;
				rt->color_reflect.r = 0;
				rt->color_reflect.g = 0;
				rt->color_reflect.b = 0;
				rt->color_refract.r = 0;
				rt->color_refract.g = 0;
				rt->color_refract.b = 0;
			}
			if (i2 != -1 && rt->object[i2].material.shiny)
			{
				reflections(rt, ray, rt->eye, 0, 0);
				i2 = intersection(rt, ray, rt->eye);
			}
			if (i2 != -1 && rt->object[i2].material.transparent)
			{
				refractions(rt, ray, rt->eye, 0, 0, 1);
				i2 = intersection(rt, ray, rt->eye);
			}
			if ((i2 != -1 && rt->object[i2].material.transparent) ||
			(i2 != -1 && rt->object[i2].material.shiny))
			{
				rt->color2.r = rt->color_reflect.r + rt->color_refract.r;
				rt->color2.g = rt->color_reflect.g + rt->color_refract.g;
				rt->color2.b = rt->color_reflect.b + rt->color_refract.b;
			}
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
