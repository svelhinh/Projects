/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 11:26:59 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/30 17:36:12 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	color(t_rt *rt, float red, float green, float blue)
{
	rt->global_color.red += rt->angle * rt->light.intensity.red
		* red;
	rt->global_color.green += rt->angle
		* rt->light.intensity.green * green;
	rt->global_color.blue += rt->angle
		* rt->light.intensity.blue * blue;
}

void		light_sphere(t_rt *rt, float t, float tmp, int cobj)
{
	t_vector3d	scaled;
	t_vector3d	newstart;
	t_vector3d	normal;
	t_vector3d	light_vec;
	t_ray		light_ray;

	scaled = vectorscale(t, &rt->r.dir);
	newstart = vectoradd(&rt->r.start, &scaled);
	normal = vectorsub(&newstart, &rt->s[cobj].pos, 0);
	tmp = 1 / sqrt(vectordot(&normal, &normal, 0));
	normal = vectorscale(tmp, &normal);
	light_vec = vectorsub(&rt->light.pos, &newstart, 0);
	if (vectordot(&normal, &light_vec, 0) > 0)
	{
		light_ray.start = newstart;
		tmp = sqrt(vectordot(&light_vec, &light_vec, 0));
		light_vec = vectorscale((1 / tmp), &light_vec);
		light_ray.dir = light_vec;
		if (!shadows(rt, &light_ray, tmp))
		{
			rt->angle = vectordot(&light_vec, &normal, 0);
			color(rt, rt->s[cobj].color.red, rt->s[cobj].color.green,
					rt->s[cobj].color.blue);
		}
	}
}

void		light_plane(t_rt *rt, float t, int cobj)
{
	t_vector3d	ptinter;
	t_vector3d	light_vec;
	t_vector3d	normal;
	t_ray		light_ray;

	ptinter.x = rt->r.start.x + rt->r.dir.x * t;
	ptinter.y = rt->r.start.y + rt->r.dir.y * t;
	ptinter.z = rt->r.start.z + rt->r.dir.z * t;
	light_vec = vectorsub(&ptinter, &rt->light.pos, 0);
	normal = normalize(&rt->p[cobj].norm);
	light_vec = normalize(&light_vec);
	light_ray.start = ptinter;
	light_ray.dir = vectorscale(-1, &light_vec);
	if (!shadows(rt, &light_ray, t))
		if ((rt->angle = vectordot(&normal, &light_vec, 0)) > 0)
			color(rt, rt->p[cobj].color.red, rt->p[cobj].color.green,
					rt->p[cobj].color.blue);
}

void		light_cylinder(t_rt *rt, float t, int cobj)
{
	t_vector3d	ptinter;
	t_vector3d	light_vec;
	t_vector3d	normalcy;
	float		m;
	t_vector3d	tmp;
	t_vector3d	tmp2;
	t_vector3d	x;
	t_ray		light_ray;

	ptinter.x = rt->r.start.x + rt->r.dir.x * t;
	ptinter.y = rt->r.start.y + rt->r.dir.y * t;
	ptinter.z = rt->r.start.z + rt->r.dir.z * t;
	light_vec = vectorsub(&rt->light.pos, &ptinter, 0);
	x = vectorsub(&rt->r.start, &rt->c[cobj].start, 0);
	m = vectordot(&rt->r.dir, &rt->c[cobj].vec, 0) * t + vectordot(&x, &rt->c[cobj].vec, 0);
	tmp = vectorscale(m, &rt->c[cobj].vec);
	tmp2 = vectorsub(&ptinter, &rt->c[cobj].start, 0);
	normalcy = vectorsub(&tmp2, &tmp, 0);
	normalcy = normalize(&normalcy);
	light_vec = normalize(&light_vec);
	light_ray.start = ptinter;
	light_ray.dir = light_vec;
	if (!shadows(rt, &light_ray, t))
		if ((rt->angle = vectordot(&normalcy, &light_vec, 0)) > 0)
			color(rt, rt->c[cobj].color.red, rt->c[cobj].color.green,
					rt->c[cobj].color.blue);
}

void		light_cone(t_rt *rt, float t, float tmp, int cobj)
{
	t_vector3d	scaled;
	t_vector3d	newstart;
	t_vector3d	normal;
	t_vector3d	light_vec;
	t_ray		light_ray;

	scaled = vectorscale(t, &rt->r.dir);
	newstart = vectoradd(&rt->r.start, &scaled);
	normal = vectorsub(&newstart, &rt->co[cobj].pos, 0);
	tmp = 1 / sqrt(vectordot(&normal, &normal, 0));
	normal = vectorscale(tmp, &normal);
	light_vec = vectorsub(&rt->light.pos, &newstart, 0);
	if (vectordot(&normal, &light_vec, 0) > 0)
	{
		light_ray.start = newstart;
		tmp = sqrt(vectordot(&light_vec, &light_vec, 0));
		light_vec = vectorscale((1 / tmp), &light_vec);
		light_ray.dir = light_vec;
		if (!shadows(rt, &light_ray, tmp))
		{
			rt->angle = vectordot(&light_vec, &normal, 0);
			color(rt, rt->co[cobj].color.red, rt->co[cobj].color.green,
					rt->co[cobj].color.blue);
		}
	}
}
