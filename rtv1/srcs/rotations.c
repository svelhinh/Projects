/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:03:54 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/30 13:49:55 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector3d	rotations(t_vector3d normal, float x, float y, float z)
{
	float	tmpx;
	float	tmpy;
	float	tmpz;

	tmpx = normal.x;
	tmpy = normal.y;
	tmpz = normal.z;
	normal.x = tmpx * cos(y) * cos(z) - tmpy * cos(y) * sin(z) + tmpz * sin(y);
	normal.y = tmpx * (cos(x) * sin(z) + sin(x) * sin(y) * cos(z)) + tmpy *
		(cos(x) * cos(z) - sin(x) * sin(y) * sin(z)) - tmpz * sin(x) * cos(y);
	normal.z = tmpx * (sin(x) * sin(z) - cos(x) * sin(y) * cos(z)) + tmpy *
		(sin(x) * cos(z) + cos(x) * sin(y) * sin(z)) + tmpz * cos(x) * cos(y);
	return (normal);
}
