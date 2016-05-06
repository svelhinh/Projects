/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflec_refrac.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 11:18:24 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/06 17:03:16 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector	reflections(t_env *rt, t_vector ray)
{
	t_vector 	tmp_reflect;
	t_vector 	n;

	intersection(rt, ray, rt->orig);
	if (!rt->i2)
	{
		rt->inter = calcul_ptinter(rt->orig, ray, rt->t);
		calcul_light(rt, rt->i2, ray);
	}
	if (!rt->reflection)
		rt->prev_refl = rt->object[rt->i2].material.reflection;
	if (rt->object[rt->i2].name != PLANE)
		n = vecsub(&rt->object[rt->i2].center, &rt->inter);
	else
		n = rt->object[rt->i2].center;
	n = normalize(&n);
	tmp_reflect.x = ray.x;
	tmp_reflect.y = ray.y;
	tmp_reflect.z = ray.z;
	ray.x = -2 * n.x * vecdot(&n, &tmp_reflect) + tmp_reflect.x;
	ray.y = -2 * n.y * vecdot(&n, &tmp_reflect) + tmp_reflect.y;
	ray.z = -2 * n.z * vecdot(&n, &tmp_reflect) + tmp_reflect.z;
	return (ray);
}

static t_vector	refractions(t_env *rt, t_vector ray)
{
	double		root;
	t_vector	tmp_refract;
	t_vector	n;
	double		i_refract;

	intersection(rt, ray, rt->orig);
	if (!rt->i2)
	{
		rt->inter = calcul_ptinter(rt->orig, ray, rt->t);
		calcul_light(rt, rt->i2, ray);
	}
	if (!rt->refraction)
		rt->prev_refr = rt->object[rt->i2].material.refraction;
	if (rt->object[rt->i2].name != PLANE)
		n = vecsub(&rt->object[rt->i2].center, &rt->inter);
	else
		n = rt->object[rt->i2].center;
	n = normalize(&n);
	i_refract = rt->object[rt->i2].material.i_refract / rt->prev_refract;
	rt->prev_refract = rt->object[rt->i2].material.i_refract;
	tmp_refract.x = ray.x;
	tmp_refract.y = ray.y;
	tmp_refract.z = ray.z;
	root = 1 + i_refract * i_refract * (vecdot(&tmp_refract, &n) * vecdot(&tmp_refract, &n) - 1);
	root = (root < 0) ? (0) : (root);
	ray.x = i_refract * tmp_refract.x + (i_refract * vecdot(&tmp_refract, &n) - sqrt(root)) * n.x;
	ray.y = i_refract * tmp_refract.y + (i_refract * vecdot(&tmp_refract, &n) - sqrt(root)) * n.y;
	ray.z = i_refract * tmp_refract.z + (i_refract * vecdot(&tmp_refract, &n) - sqrt(root)) * n.z;
	return (ray);
}

void	reflec_refrac(t_env *rt, int rr, t_vector rayrefl, t_vector rayrefr)
{
	t_vector	ray;

	if (!rr)
	{
		ray = rt->ray;
		intersection(rt, ray, rt->orig);
		rt->inter = calcul_ptinter(rt->orig, ray, rt->t);
		calcul_light(rt, rt->i2, ray);
		rt->color2 = rt->color;
	}
	if (rt->reflection < rt->max_reflect && rt->object[rt->i2].material.shiny)
	{
		ray = rayrefl;
		rayrefl = reflections(rt, ray);
		rt->reflection++;
	}
	if (rt->refraction < rt->max_refract && rt->object[rt->i2].material.transparent)
	{
		ray = rayrefr;
		rayrefr = refractions(rt, ray);
		rt->refraction++;
	}
	if ((rt->reflection < rt->max_reflect && rt->object[rt->i2].material.shiny) ||
		(rt->refraction < rt->max_refract && rt->object[rt->i2].material.transparent))
	{
		rt->orig = rt->inter;
		rt->color2.r = rt->color.r * rt->prev_refl + rt->color.r * rt->prev_refr + rt->color2.r * (1 - rt->prev_refl) + rt->color2.r * (1 - rt->prev_refr);
		rt->color2.g = rt->color.g * rt->prev_refl + rt->color.g * rt->prev_refr + rt->color2.g * (1 - rt->prev_refl) + rt->color2.g * (1 - rt->prev_refr);
		rt->color2.b = rt->color.b * rt->prev_refl + rt->color.b * rt->prev_refr + rt->color2.b * (1 - rt->prev_refl) + rt->color2.b * (1 - rt->prev_refr);
	}
	if (rr < rt->max_reflect + rt->max_refract)
		reflec_refrac(rt, rr + 1, rayrefl, rayrefr);
}
