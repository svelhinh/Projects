/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflec_refrac.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 11:18:24 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/09 14:30:20 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	reflections(t_env *rt, t_vector ray, t_vector orig, int rfl, int rfr)
{
	t_vector	n;
	t_vector	tmp_reflect;
	int			i2;

	i2 = intersection(rt, ray, orig);
	rt->inter = calcul_ptinter(orig, ray, rt->t);
	calcul_light(rt, i2, ray);
	if (rfl < rt->max_reflect && rt->object[i2].material.shiny && i2 != -1)
	{
		if (rt->object[i2].name != PLANE)
			n = vecsub(&rt->object[i2].center, &rt->inter);
		else
			n = rt->object[i2].center;
		n = normalize(&n);
		tmp_reflect.x = ray.x;
		tmp_reflect.y = ray.y;
		tmp_reflect.z = ray.z;
		ray.x = -2 * n.x * vecdot(&n, &tmp_reflect) + tmp_reflect.x;
		ray.y = -2 * n.y * vecdot(&n, &tmp_reflect) + tmp_reflect.y;
		ray.z = -2 * n.z * vecdot(&n, &tmp_reflect) + tmp_reflect.z;
		orig = rt->inter;
	}
	rt->color_reflect.r = rt->color.r * rt->first_reflec + rt->color_reflect.r * (1 - rt->first_reflec);
	rt->color_reflect.g = rt->color.g * rt->first_reflec + rt->color_reflect.g * (1 - rt->first_reflec);
	rt->color_reflect.b = rt->color.b * rt->first_reflec + rt->color_reflect.b * (1 - rt->first_reflec);
	if (rfl < rt->max_reflect && rt->object[i2].material.shiny && i2 != -1)
		reflections(rt, ray, orig, rfl + 1, rfr);
	if (rfr < rt->max_refract && rt->object[i2].material.transparent && i2 != -1)
		refractions(rt, ray, orig, rfl, rfr + 1, rt->object[i2].material.i_refract);
}

void	refractions(t_env *rt, t_vector ray, t_vector orig, int rfl, int rfr, double prev_refr)
{
	double		root;
	t_vector	tmp_refract;
	t_vector	n;
	double		i_refract;
	int			i2;

	i2 = intersection(rt, ray, orig);
	rt->inter = calcul_ptinter(orig, ray, rt->t);
	calcul_light(rt, i2, ray);
	if (rfr < rt->max_refract && rt->object[i2].material.transparent && i2 != -1)
	{
		if (rt->object[i2].name != PLANE)
			n = vecsub(&rt->object[i2].center, &rt->inter);
		else
			n = rt->object[i2].center;
		n = normalize(&n);
		i_refract = rt->object[i2].material.i_refract / prev_refr;
		prev_refr = rt->object[i2].material.i_refract;
		tmp_refract.x = ray.x;
		tmp_refract.y = ray.y;
		tmp_refract.z = ray.z;
		root = 1 + i_refract * i_refract * (vecdot(&tmp_refract, &n) * vecdot(&tmp_refract, &n) - 1);
		root = (root < 0) ? (0) : (root);
		ray.x = i_refract * tmp_refract.x + (i_refract * vecdot(&tmp_refract, &n) - sqrt(root)) * n.x;
		ray.y = i_refract * tmp_refract.y + (i_refract * vecdot(&tmp_refract, &n) - sqrt(root)) * n.y;
		ray.z = i_refract * tmp_refract.z + (i_refract * vecdot(&tmp_refract, &n) - sqrt(root)) * n.z;
		orig = rt->inter;
	}
	rt->color_refract.r = rt->color.r * rt->first_refrac + rt->color_refract.r * (1 - rt->first_refrac);
	rt->color_refract.g = rt->color.g * rt->first_refrac + rt->color_refract.g * (1 - rt->first_refrac);
	rt->color_refract.b = rt->color.b * rt->first_refrac + rt->color_refract.b * (1 - rt->first_refrac);
	if (rfl < rt->max_reflect && rt->object[i2].material.shiny && i2 != -1)
		reflections(rt, ray, orig, rfl + 1, rfr);
	if (rfr < rt->max_refract && rt->object[i2].material.transparent && i2 != -1)
		refractions(rt, ray, orig, rfl, rfr + 1, rt->object[i2].material.i_refract);
}
