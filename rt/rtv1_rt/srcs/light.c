/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 10:01:53 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/26 19:00:35 by svelhinh         ###   ########.fr       */
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
		if ((rt->object[i].name == SPHERE && sphere(&ray_light, &rt->object[i], &t, inter)) ||
			(rt->object[i].name == CYLINDER && cylinder(&ray_light, &rt->object[i], &t, inter)) ||
			(rt->object[i].name == CONE && cone(&ray_light, &rt->object[i], &t, inter)))
			return (1);
		i++;
	}
	return (0);
}

void	light(t_env *rt, t_figure object, t_vector lpos, t_vector inter)
{
	t_vector	n;
	t_vector	light;
	double		angle;

	light = vecsub(&inter, &lpos);
	if (!shadows(rt, light, inter))
	{
		n = vecsub(&object.center, &inter);
		if (object.name == CYLINDER || object.name == CONE)
			n.y = 0;
		if (object.name == PLANE)
 	 		n = object.center;
		angle = vecdot(&n, &light) / (sqrt(pow(light.x, 2) + pow(light.y, 2)
		+ pow(light.z, 2)) * sqrt(pow(n.x, 2) + pow(n.y, 2) + pow(n.z, 2)));
		if (angle > 0)
			rt->color = (int)(angle * object.color.r * 255) * 0x10000 +
						(int)(angle * object.color.g * 255) * 0x100 +
						(int)(angle * object.color.b * 255);
	}
}
