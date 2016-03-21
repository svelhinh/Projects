/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 11:26:59 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/21 12:32:01 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	light_sphere(t_rt *rt, float t, float tmp, int currentobj)
{
	t_vector3d	scaled;
	t_vector3d	newstart;
	t_vector3d	normal;
	t_vector3d	dist;
	t_ray		light_ray;

	scaled = vectorscale(t, &rt->r.dir);
	newstart = vectoradd(&rt->r.start, &scaled);
	normal = vectorsub(&newstart, &rt->s[currentobj].pos, 0);
	tmp = vectordot(&normal, &normal, 0);
	if (tmp != 0)
	{
		tmp = 1 / sqrt(tmp);
		normal = vectorscale(tmp, &normal);
		dist = vectorsub(&rt->light.pos, &newstart, 0);
		if (vectordot(&normal, &dist, 0) > 0)
		{
			tmp = sqrt(vectordot(&dist, &dist, 0));
			if (tmp > 0)
			{
				light_ray.start = newstart;
				light_ray.dir = vectorscale((1 / tmp), &dist);
				tmp = vectordot(&light_ray.dir, &normal, 0);
				rt->global_color.red += tmp * rt->light.intensity.red * rt->s[currentobj].color.red;
				rt->global_color.green += tmp * rt->light.intensity.green * rt->s[currentobj].color.green;
				rt->global_color.blue += tmp * rt->light.intensity.blue * rt->s[currentobj].color.blue;
			}
		}
	}
}

void	light_plane(t_rt *rt, float t, float tmp, int currentobj)
{
	t_vector3d		light_vec;
	t_vector3d		inter;
	float			angle;
	float			inter_dist;
	float			dist;
	float			light_dist;

	(void)tmp;
	(void)t;
	dist = sqrt(pow(rt->r.start.x, 2) + pow(rt->r.start.y, 2) + pow(rt->r.start.z, 2));
	inter.x = rt->r.start.x + rt->r.dir.x * dist;
	inter.y = rt->r.start.y + rt->r.dir.y * dist;
	inter.z = rt->r.start.z + rt->r.dir.z * dist;
	light_vec = vectorsub(&inter, &rt->light.pos, 0);
	light_dist = sqrt(pow(light_vec.x, 2) + pow(light_vec.y, 2) + pow(light_vec.z, 2));
	light_vec.x /= light_dist;
	light_vec.y /= light_dist;
	light_vec.z /= light_dist;
	inter_dist = sqrt(pow(inter.x, 2) + pow(inter.y, 2) + pow(inter.z, 2));
	inter.x /= inter_dist;
	inter.y /= inter_dist;
	inter.z /= inter_dist;
	angle = vectordot(&light_vec, &inter, 0);
	if (angle > 0)
	{
		//printf("inter.x : %f\ninter.y : %f\ninter.z : %f\n\n", inter.x, inter.y, inter.z);
		printf("angle : %f\n", angle);
		rt->global_color.red += angle * rt->light.intensity.red * rt->p[currentobj].color.red;
		rt->global_color.green += angle * rt->light.intensity.green * rt->p[currentobj].color.green;
		rt->global_color.blue += angle * rt->light.intensity.blue * rt->p[currentobj].color.blue;
	}
	/*t_vector3d	scaled;
	t_vector3d	inter;
	t_vector3d	normal;
	t_vector3d	light_vec;
	t_ray		light_ray;
	float		angle;

	scaled = vectorscale(t, &rt->r.dir);
	inter = vectoradd(&rt->r.start, &scaled);
	normal = vectorsub(&inter, &rt->p[currentobj].pos, 0);
	tmp = vectordot(&normal, &normal, 0);
	if (tmp != 0)
	{
		tmp = 1 / sqrt(tmp);
		normal = vectorscale(tmp, &normal);
		light_vec = vectorsub(&inter, &rt->light.pos, 0);
		if (vectordot(&normal, &light_vec, 0) > 0)
		{
			tmp = sqrt(vectordot(&light_vec, &light_vec, 0));
			if (tmp > 0)
			{
				light_ray.dir = vectorscale((1 / tmp), &light_vec);
				angle = vectordot(&light_ray.dir, &normal, 0);
				if (angle > 0)
				{
					printf("angle : %f\n", angle);
					rt->global_color.red += angle * rt->light.intensity.red * rt->p[currentobj].color.red;
					rt->global_color.green += angle * rt->light.intensity.green * rt->p[currentobj].color.green;
					rt->global_color.blue += angle * rt->light.intensity.blue * rt->p[currentobj].color.blue;
				}
			}
		}
	}*/
}

void	light_cylinder(t_rt *rt, float t, float tmp, int currentobj)
{
	t_vector3d	scaled;
	t_vector3d	newstart;
	t_vector3d	normal;
	t_vector3d	dist;
	t_ray		light_ray;

	scaled = vectorscale(t, &rt->r.dir);
	newstart = vectoradd(&rt->r.start, &scaled);
	normal = vectorsub(&newstart, &rt->c[currentobj].pos, 0);
	tmp = vectordot(&normal, &normal, 0);
	if (tmp != 0)
	{
		tmp = 1 / sqrt(tmp);
		normal = vectorscale(tmp, &normal);
		dist = vectorsub(&rt->light.pos, &newstart, 0);
		if (vectordot(&normal, &dist, 0) > 0)
		{
			tmp = sqrt(vectordot(&dist, &dist, 0));
			if (tmp > 0)
			{
				light_ray.start = newstart;
				light_ray.dir = vectorscale((1 / tmp), &dist);
				tmp = vectordot(&light_ray.dir, &normal, 0);
				rt->global_color.red += tmp * rt->light.intensity.red * rt->c[currentobj].color.red;
				rt->global_color.green += tmp * rt->light.intensity.green * rt->c[currentobj].color.green;
				rt->global_color.blue += tmp * rt->light.intensity.blue * rt->c[currentobj].color.blue;
			}
		}
	}
}

void	light_cone(t_rt *rt, float t, float tmp, int currentobj)
{
	t_vector3d	scaled;
	t_vector3d	newstart;
	t_vector3d	normal;
	t_vector3d	dist;
	t_ray		light_ray;

	scaled = vectorscale(t, &rt->r.dir);
	newstart = vectoradd(&rt->r.start, &scaled);
	normal = vectorsub(&newstart, &rt->co[currentobj].pos, 0);
	tmp = vectordot(&normal, &normal, 0);
	if (tmp != 0)
	{
		tmp = 1 / sqrt(tmp);
		normal = vectorscale(tmp, &normal);
		dist = vectorsub(&rt->light.pos, &newstart, 0);
		if (vectordot(&normal, &dist, 0) > 0)
		{
			tmp = sqrt(vectordot(&dist, &dist, 0));
			if (tmp > 0)
			{
				light_ray.start = newstart;
				light_ray.dir = vectorscale((1 / tmp), &dist);
				tmp = vectordot(&light_ray.dir, &normal, 0);
				rt->global_color.red += tmp * rt->light.intensity.red * rt->co[currentobj].color.red;
				rt->global_color.green += tmp * rt->light.intensity.green * rt->co[currentobj].color.green;
				rt->global_color.blue += tmp * rt->light.intensity.blue * rt->co[currentobj].color.blue;
			}
		}
	}
}
