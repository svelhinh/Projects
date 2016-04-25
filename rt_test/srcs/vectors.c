/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:29:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/22 18:18:04 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector3d	vecsub(t_vector3d *v1, t_vector3d *v2)
{
	t_vector3d result;

	result.x = v2->x - v1->x;
	result.y = v2->y - v1->y;
	result.z = v2->z - v1->z;
	return (result);
}

double		vecdot(t_vector3d *v1, t_vector3d *v2)
{
	double	resx;
	double	resy;
	double	resz;
	double	result;

	resx = v1->x * v2->x;
	resy = v1->y * v2->y;
	resz = v1->z * v2->z;
	result = resx + resy + resz;
	return (result);
}

t_vector3d	normalize(t_vector3d *v1)
{
	t_vector3d	res;
	double		vdist;

	vdist = sqrt(vecdot(v1, v1));
	res.x = v1->x / vdist;
	res.y = v1->y / vdist;
	res.z = v1->z / vdist;
	return (res);
}
