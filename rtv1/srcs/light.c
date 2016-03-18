/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 11:26:59 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/18 13:50:25 by svelhinh         ###   ########.fr       */
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
	t_vector3d	scaled;
	t_vector3d	newstart;
	t_vector3d	normal;
	t_vector3d	dist;
	t_ray		light_ray;

	scaled = vectorscale(t, &rt->r.dir);
	newstart = vectoradd(&rt->r.start, &scaled);
	normal = vectorsub(&newstart, &rt->p[currentobj].pos, 0);
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
				rt->global_color.red += tmp * rt->light.intensity.red * rt->p[currentobj].color.red;
				rt->global_color.green += tmp * rt->light.intensity.green * rt->p[currentobj].color.green;
				rt->global_color.blue += tmp * rt->light.intensity.blue * rt->p[currentobj].color.blue;
			}
		}
	}
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
