/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:29:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/31 15:39:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector3d	vectorsub(t_vector3d *v1, t_vector3d *v2/*, int i*/)
{
	t_vector3d result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	// result.x = (i == 1) ? (0) : (result.x);
	// result.y = (i == 2) ? (0) : (result.y);
	// result.z = (i == 3) ? (0) : (result.z);
	return (result);
}

double		vectordot(t_vector3d *v1, t_vector3d *v2/*, int i*/)
{
	double	resx;
	double	resy;
	double	resz;
	double	result;

	resx = v1->x * v2->x;
	resy = v1->y * v2->y;
	resz = v1->z * v2->z;
	// resx = (i == 1) ? (0) : (resx);
	// resy = (i == 2) ? (0) : (resy);
	// resz = (i == 3) ? (0) : (resz);
	// if (i == 'x')
	// 	result = -resx + resy + resz;
	// else if (i == 'y')
	// 	result = resx - resy + resz;
	// else if (i == 'z')
	// 	result = resx + resy - resz;
	// else
		result = resx + resy + resz;
	return (result);
}

// t_vector3d	vectorscale(double c, t_vector3d *v)
// {
// 	t_vector3d res;

// 	res.x = v->x * c;
// 	res.y = v->y * c;
// 	res.z = v->z * c;
// 	return (res);
// }

// t_vector3d	vectoradd(t_vector3d *v1, t_vector3d *v2)
// {
// 	t_vector3d res;

// 	res.x = v1->x + v2->x;
// 	res.y = v1->y + v2->y;
// 	res.z = v1->z + v2->z;
// 	return (res);
// }

// t_vector3d	normalize(t_vector3d *v1)
// {
// 	t_vector3d	res;
// 	double		vdist;

// 	vdist = sqrt(vectordot(v1, v1, 0));
// 	res.x = v1->x / vdist;
// 	res.y = v1->y / vdist;
// 	res.z = v1->z / vdist;
// 	return (res);
// }
