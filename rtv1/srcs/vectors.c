/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 11:10:35 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/13 11:10:44 by svelhinh         ###   ########.fr       */
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
