/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:50:53 by svelhinh          #+#    #+#             */
/*   Updated: 2018/06/29 19:10:59 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

const char	*gl_type_to_string(GLenum type)
{
	if (type == GL_BOOL)
		return ("bool");
	if (type == GL_INT)
		return ("int");
	if (type == GL_FLOAT)
		return ("float");
	if (type == GL_FLOAT_VEC2)
		return ("vec2");
	if (type == GL_FLOAT_VEC3)
		return ("vec3");
	if (type == GL_FLOAT_VEC4)
		return ("vec4");
	if (type == GL_FLOAT_MAT2)
		return ("mat2");
	if (type == GL_FLOAT_MAT3)
		return ("mat3");
	if (type == GL_FLOAT_MAT4)
		return ("mat4");
	if (type == GL_SAMPLER_2D)
		return ("sampler2D");
	if (type == GL_SAMPLER_3D)
		return ("sampler3D");
	if (type == GL_SAMPLER_CUBE)
		return ("samplerCube");
	if (type == GL_SAMPLER_2D_SHADOW)
		return ("sampler2DShadow");
	return ("other");
}

int			rand_between_2_numbers(int min, int max)
{
	return ((rand() % (max - min)) + min);
}

void		recenter_object(t_obj *obj)
{
	int		i;
	t_vec3	sum;

	i = 0;
	sum.x = 0;
	sum.y = 0;
	sum.z = 0;
	while (i < obj->nb_points * 3)
	{
		sum.x += obj->points[i];
		sum.y += obj->points[i + 1];
		sum.z += obj->points[i + 2];
		i += 3;
	}
	obj->center_pt.x = sum.x / (float)obj->nb_points;
	obj->center_pt.y = sum.y / (float)obj->nb_points;
	obj->center_pt.z = sum.z / (float)obj->nb_points;
	i = 0;
	while (i < obj->nb_points * 3)
	{
		obj->points[i] -= obj->center_pt.x;
		obj->points[i + 1] -= obj->center_pt.y;
		obj->points[i + 2] -= obj->center_pt.z;
		i += 3;
	}
}

int			is_dir(const char *path)
{
	struct stat buf;

	stat(path, &buf);
	return (S_ISDIR(buf.st_mode));
}
