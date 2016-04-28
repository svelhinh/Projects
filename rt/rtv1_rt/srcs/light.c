/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 10:01:53 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/28 15:39:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	shadows(t_env *rt, t_vector ray_light, t_vector inter)
{
	int			i;
	double		t;

	i = 0;
	t = rt->t;
	while (i < rt->nbobj)
	{
		if ((rt->object[i].name == SPHERE && sphere(ray_light, rt->object[i], &t, inter)) ||
			(rt->object[i].name == CYLINDER && cylinder(ray_light, rt->object[i], &t, inter)) ||
			(rt->object[i].name == CONE && cone(ray_light, rt->object[i], &t, inter)))
			return (1);
		i++;
	}
	return (0);
}

static double	specular_light(t_vector n, t_vector light, t_figure object, t_vector ray)
{
	double		spec;
	t_vector	r;

	ray = normalize(&ray);
	light = vecscale(&light, -1);
	ray = normalize(&light);
	r.x = light.x - 2 * n.x * vecdot(&n, &light);
	r.y = light.y - 2 * n.y * vecdot(&n, &light);
	r.z = light.z - 2 * n.z * vecdot(&n, &light);
	r = normalize(&r);
	spec = object.specular * pow(vecdot(&r, &ray), object.specular_power);
	return (spec);
}

void		light(t_env *rt, t_figure object, t_light light, t_vector inter, t_vector ray)
{
	t_vector	n;
	t_vector	light2;
	double		angle;
	double		spec;
	t_color		tmp_color;
	t_vector	tmp;
	t_vector	tmp2;
	t_vector	tmp3;
	t_vector	tmp4;

	if (object.name == CYLINDER || object.name == CONE)
	{
		tmp = rotations(light.center, object.angle.x, object.angle.y, object.angle.z);
		tmp2 = rotations(inter, object.angle.x, object.angle.y, object.angle.z);
	 	tmp3 = rotations(object.center, object.angle.x, object.angle.y, object.angle.z);
		light2 = vecsub(&tmp2, &tmp);
		tmp4 = vecsub(&inter, &light.center);
	}
	else
	{
		tmp = light.center;
		tmp2 = inter;
		tmp3 = object.center;
		tmp4 = vecsub(&inter, &light.center);
		light2 = tmp4;
	}
	if (!shadows(rt, tmp4, inter))
	{
		n = vecsub(&tmp3, &tmp2);
		if (object.name == CYLINDER || object.name == CONE)
			n.y = 0;
		if (object.name == PLANE)
 	 		n = tmp3;
		angle = vecdot(&n, &light2) / (sqrt(pow(light2.x, 2) + pow(light2.y, 2)
		+ pow(light2.z, 2)) * sqrt(pow(n.x, 2) + pow(n.y, 2) + pow(n.z, 2)));
		if (angle > 0)
		{
			spec = specular_light(n, light2, object, ray);
			tmp_color.r = angle * object.color.r * 255;
			tmp_color.g = angle * object.color.g * 255;
			tmp_color.b = angle * object.color.b * 255;
			tmp_color.r = (tmp_color.r > 0xff) ? (0xff) : (tmp_color.r);
			tmp_color.g = (tmp_color.g > 0xff) ? (0xff) : (tmp_color.g);
			tmp_color.b = (tmp_color.b > 0xff) ? (0xff) : (tmp_color.b);
			rt->color.r += tmp_color.r + spec + 255 * light.color.r;
			rt->color.g += tmp_color.g + spec + 255 * light.color.g;
			rt->color.b += tmp_color.b + spec + 255 * light.color.b;
		}
	}
}
