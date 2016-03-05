/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 11:10:35 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/05 11:12:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector3d	vectorsub(t_vector3d *v1, t_vector3d *v2)
{
	t_vector3d result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

float		vectordot(t_vector3d *v1, t_vector3d *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}
