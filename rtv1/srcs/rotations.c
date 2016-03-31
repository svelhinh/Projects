/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:03:54 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/31 12:38:21 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		parsing_rotations(t_rt *rt, int j, int i, char **line2)
{
	if (j == 'p')
	{
		rt->p[i].rot.x = ft_atof(line2[2]);
		rt->p[i].rot.y = ft_atof(line2[3]);
		rt->p[i].rot.z = ft_atof(line2[4]);
	}
	if (j == 'c')
	{
		rt->c[i].rot.x = ft_atof(line2[2]);
		rt->c[i].rot.y = ft_atof(line2[3]);
		rt->c[i].rot.z = ft_atof(line2[4]);
		rt->c[i].vec = rotations(rt->c[i].vec, rt->c[i].rot.x, rt->c[i].rot.y, rt->c[i].rot.z);
	}
	if (j == 'o')
	{
		rt->co[i].rot.x = -ft_atof(line2[2]);
		rt->co[i].rot.y = -ft_atof(line2[3]);
		rt->co[i].rot.z = -ft_atof(line2[4]);
	}
}

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
