/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 11:26:59 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/24 13:32:14 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	light_sphere(t_rt *rt, float t, float tmp, int currentobj)
{
	t_vector3d	scaled;
	t_vector3d	newstart;
	t_vector3d	normal;
	t_vector3d	light_vec;

	scaled = vectorscale(t, &rt->r.dir);
	newstart = vectoradd(&rt->r.start, &scaled);
	normal = vectorsub(&newstart, &rt->s[currentobj].pos, 0);
	tmp = 1 / sqrt(vectordot(&normal, &normal, 0));
	normal = vectorscale(tmp, &normal);
	light_vec = vectorsub(&rt->light.pos, &newstart, 0);
	if (vectordot(&normal, &light_vec, 0) > 0)
	{
		tmp = sqrt(vectordot(&light_vec, &light_vec, 0));
		light_vec = vectorscale((1 / tmp), &light_vec);
		tmp = vectordot(&light_vec, &normal, 0);
		rt->global_color.red += tmp * rt->light.intensity.red * rt->s[currentobj].color.red;
		rt->global_color.green += tmp * rt->light.intensity.green * rt->s[currentobj].color.green;
		rt->global_color.blue += tmp * rt->light.intensity.blue * rt->s[currentobj].color.blue;
	}
}

void	light_plane(t_rt *rt, float t, float tmp, int currentobj)
{
	t_vector3d	ptinter;
	t_vector3d	light_vec;
	float		norme_cam;
	float		norme_light;
	float		angle;
	float		intensity;
	(void)tmp;

	ptinter.x = rt->r.start.x + rt->r.dir.x * t;
	ptinter.y = rt->r.start.y + rt->r.dir.y * t;
	ptinter.z = rt->r.start.z + rt->r.dir.z * t;
	light_vec = vectorsub(&ptinter, &rt->light.pos, 0);
	norme_cam = sqrt(pow(rt->r.dir.x, 2) + pow(rt->r.dir.y, 2) + pow(rt->r.dir.z, 2));
	norme_light = sqrt(pow(light_vec.x, 2) + pow(light_vec.y, 2) + pow(light_vec.z, 2));
	angle = acos(vectordot(&rt->r.dir, &light_vec, 0) / (norme_cam * norme_light));
	angle *= 180 / 3.14;
	intensity = fabs(angle - 90);
	angle = 1 - 1 / intensity;
	if (angle > 0)
	{
		rt->global_color.red += angle * rt->light.intensity.red * rt->p[currentobj].color.red;
		rt->global_color.green += angle * rt->light.intensity.green * rt->p[currentobj].color.green;
		rt->global_color.blue += angle * rt->light.intensity.blue * rt->p[currentobj].color.blue;
	}
	//printf("angle : %f\n", angle);
	/*t_vector3d	scaled;
	t_vector3d	newstart;
	t_vector3d	normal;
	t_vector3d	light_vec;

	scaled = vectorscale(t, &rt->r.dir);
	newstart = vectoradd(&rt->r.start, &scaled);
	normal = vectorsub(&newstart, &rt->p[currentobj].pos, 0);
	tmp = 1 / sqrt(vectordot(&normal, &normal, 0));
	normal = vectorscale(tmp, &normal);
	light_vec = vectorsub(&rt->light.pos, &newstart, 0);
	if (vectordot(&normal, &light_vec, 0) > 0)
	{
		tmp = sqrt(vectordot(&light_vec, &light_vec, 0));
		//printf("tmp = %f\n", tmp);
		light_vec = vectorscale((1 / tmp), &light_vec);
		tmp = vectordot(&light_vec, &normal, 0);
		rt->global_color.red += tmp * rt->light.intensity.red * rt->p[currentobj].color.red;
		rt->global_color.green += tmp * rt->light.intensity.green * rt->p[currentobj].color.green;
		rt->global_color.blue += tmp * rt->light.intensity.blue * rt->p[currentobj].color.blue;
	}*/
}

void	light_cylinder(t_rt *rt, float t, float tmp, int currentobj)
{
	t_vector3d	scaled;
	t_vector3d	newstart;
	t_vector3d	normal;
	t_vector3d	light_vec;

	scaled = vectorscale(t, &rt->r.dir);
	newstart = vectoradd(&rt->r.start, &scaled);
	normal = vectorsub(&newstart, &rt->c[currentobj].pos, 0);
	tmp = 1 / sqrt(vectordot(&normal, &normal, 0));
	normal = vectorscale(tmp, &normal);
	light_vec = vectorsub(&rt->light.pos, &newstart, 0);
	if (vectordot(&normal, &light_vec, 0) > 0)
	{
		tmp = sqrt(vectordot(&light_vec, &light_vec, 0));
		light_vec = vectorscale((1 / tmp), &light_vec);
		tmp = vectordot(&light_vec, &normal, 0);
		rt->global_color.red += tmp * rt->light.intensity.red * rt->c[currentobj].color.red;
		rt->global_color.green += tmp * rt->light.intensity.green * rt->c[currentobj].color.green;
		rt->global_color.blue += tmp * rt->light.intensity.blue * rt->c[currentobj].color.blue;
	}
}

void	light_cone(t_rt *rt, float t, float tmp, int currentobj)
{
	t_vector3d	scaled;
	t_vector3d	newstart;
	t_vector3d	normal;
	t_vector3d	light_vec;

	scaled = vectorscale(t, &rt->r.dir);
	newstart = vectoradd(&rt->r.start, &scaled);
	normal = vectorsub(&newstart, &rt->co[currentobj].pos, 0);
	tmp = 1 / sqrt(vectordot(&normal, &normal, 0));
	normal = vectorscale(tmp, &normal);
	light_vec = vectorsub(&rt->light.pos, &newstart, 0);
	if (vectordot(&normal, &light_vec, 0) > 0)
	{
		tmp = sqrt(vectordot(&light_vec, &light_vec, 0));
		light_vec = vectorscale((1 / tmp), &light_vec);
		tmp = vectordot(&light_vec, &normal, 0);
		rt->global_color.red += tmp * rt->light.intensity.red * rt->co[currentobj].color.red;
		rt->global_color.green += tmp * rt->light.intensity.green * rt->co[currentobj].color.green;
		rt->global_color.blue += tmp * rt->light.intensity.blue * rt->co[currentobj].color.blue;
	}
}
