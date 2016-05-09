/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:48:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/06 16:42:40 by svelhinh         ###   ########.fr       */
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

void	intersection(t_env *rt, t_vector ray, t_vector origin)
{
	int			i;

	rt->i2 = -1;
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
			rt->i2 = i;
		i++;
	}
}

static void		scan(int pas, t_env *rt)
{
	int			x;
	int			y;

	y = rt->start_h;
	while (y < rt->end_h)
	{
		x = 0;
		while (x < rt->w)
		{
			rt->ray.x = x - rt->w / 2 - rt->eye.x + rt->xx;
			rt->ray.y = y - rt->h / 2 - rt->eye.y;
			rt->ray.z = rt->w - rt->eye.z + rt->zz;
			rt->ray = rotations(rt->ray, rt->cam_angle.x, rt->cam_angle.y,
				rt->cam_angle.z);
			rt->color2.r = 0;
			rt->color2.g = 0;
			rt->color2.b = 0;
			rt->final_color = 0;
			rt->prev_refl = 1;
			rt->prev_refr = 1;
			rt->orig = rt->eye;
			rt->prev_refract = 1;
			rt->ray = normalize(&rt->ray);
			rt->reflection = 0;
			rt->refraction = 0;
			reflec_refrac(rt, 0, rt->ray, rt->ray);
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
