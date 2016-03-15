/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 11:10:35 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/15 17:04:24 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector3d	vectorsub(t_vector3d *v1, t_vector3d *v2, int i)
{
	t_vector3d result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	result.x = (i == 1) ? (0) : (result.x);
	result.y = (i == 2) ? (0) : (result.y);
	result.z = (i == 3) ? (0) : (result.z);
	return (result);
}

float		vectordot(t_vector3d *v1, t_vector3d *v2, int i)
{
	float	resx;
	float	resy;
	float	resz;
	float	result;

	resx = v1->x * v2->x;
	resy = v1->y * v2->y;
	resz = v1->z * v2->z;
	resx = (i == 1) ? (0) : (resx);
	resy = (i == 2) ? (0) : (resy);
	resz = (i == 3) ? (0) : (resz);
	if (i == 'x')
		result = -resx + resy + resz;
	else if (i == 'y')
		result = resx - resy + resz;
	else if (i == 'z')
		result = resx + resy - resz;
	else
		result = resx + resy + resz;
	return (result);
}

t_point		vectorads(t_ray *r, float t)
{
	t_point result;

	result.x = r->start.x + t * r->dir.x;
	result.y = r->start.y + t * r->dir.y;
	result.z = r->start.z + t * r->dir.z;
	return (result);
}

t_vector3d	vectordiff(t_point p, t_rt *rt, char *object, int currentobj)
{
	t_vector3d result;

	if (!ft_strcmp(object, "sphere"))
	{
		result.x = p.x - rt->s[currentobj].pos.x;
		result.y = p.y - rt->s[currentobj].pos.y;
		result.z = p.z - rt->s[currentobj].pos.z;
	}
	if (!ft_strcmp(object, "plane"))
	{
		result.x = p.x - rt->p[currentobj].pos.x;
		result.y = p.y - rt->p[currentobj].pos.y;
		result.z = p.z - rt->p[currentobj].pos.z;
	}
	return (result);
}
