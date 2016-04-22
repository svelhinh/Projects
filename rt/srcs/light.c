/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:28:22 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/22 19:11:58 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vector3d	calcul_ptinter(t_ray *r, float t)
{
	t_vector3d	ptinter;

	ptinter.x = r->start.x + r->dir.x * t;
	ptinter.y = r->start.y + r->dir.y * t;
	ptinter.z = r->start.z + r->dir.z * t;
	return (ptinter);
}

void				light_sphere(t_rt *rt, float t, t_sphere *s)
{
	t_vector3d	ptinter;
	t_vector3d	normal;
	t_vector3d	light_vec;

	ptinter = calcul_ptinter(&rt->r, t);
	light_vec = vecsub(&ptinter, &rt->light.pos);
	normal = vecsub(&s->pos, &ptinter);
	light_vec = normalize(&light_vec);
	normal = normalize(&normal);
	rt->angle = vecdot(&normal, &light_vec);
	if (rt->angle > 0.0000001)
		color(rt, s->color.r, s->color.g, s->color.b);
	else
		rt->color = rt->background_color;
}

void				light_plane(t_rt *rt, float t, t_plane *p)
{
	t_vector3d	ptinter;
	t_vector3d	light_vec;
	t_vector3d	normal;

	ptinter = calcul_ptinter(&rt->r, t);
	light_vec = vecsub(&ptinter, &rt->light.pos);
	normal = normalize(&p->norm);
	light_vec = normalize(&light_vec);
	rt->angle = vecdot(&normal, &light_vec);
	if (rt->angle > 0)
		color(rt, p->color.r, p->color.g, p->color.b);
	else
		rt->color = rt->background_color;
}

// void				light_cylinder(t_rt *rt, float t, int cobj)
// {
// 	t_vector3d	ptinter;
// 	t_vector3d	light_vec;
// 	t_vector3d	normalcy;
// 	t_vector3d	x;
// 	t_ray		light_ray;
//
// 	ptinter = calcul_ptinter(&rt->r, t);
// 	light_vec = vectorsub(&rt->light.pos, &ptinter, 0);
// 	x = vectorsub(&rt->r.start, &rt->c[cobj].start, 0);
// 	rt->m = vectordot(&rt->r.dir, &rt->c[cobj].vec, 0) * t +
// 		vectordot(&x, &rt->c[cobj].vec, 0);
// 	rt->tmp = vectorscale(rt->m, &rt->c[cobj].vec);
// 	rt->tmp2 = vectorsub(&ptinter, &rt->c[cobj].start, 0);
// 	normalcy = vectorsub(&rt->tmp2, &rt->tmp, 0);
// 	normalcy = normalize(&normalcy);
// 	light_vec = normalize(&light_vec);
// 	light_ray.start = ptinter;
// 	light_ray.dir = light_vec;
// 	if (!shadows(rt, &light_ray, t))
// 		if ((rt->angle = vectordot(&normalcy, &light_vec, 0)) > 0)
// 			color(rt, rt->c[cobj].color.red, rt->c[cobj].color.green,
// 					rt->c[cobj].color.blue);
// }
//
// void				light_cone(t_rt *rt, float t, float tmp, int cobj)
// {
// 	t_vector3d	scaled;
// 	t_vector3d	newstart;
// 	t_vector3d	normal;
// 	t_vector3d	light_vec;
// 	t_ray		light_ray;
//
// 	scaled = vectorscale(t, &rt->r.dir);
// 	newstart = vectoradd(&rt->r.start, &scaled);
// 	normal = vectorsub(&newstart, &rt->co[cobj].pos, 0);
// 	tmp = 1 / sqrt(vectordot(&normal, &normal, 0));
// 	normal = vectorscale(tmp, &normal);
// 	light_vec = vectorsub(&rt->light.pos, &newstart, 0);
// 	if (vectordot(&normal, &light_vec, 0) > 0)
// 	{
// 		light_ray.start = newstart;
// 		tmp = sqrt(vectordot(&light_vec, &light_vec, 0));
// 		light_vec = vectorscale((1 / tmp), &light_vec);
// 		light_ray.dir = light_vec;
// 		if (!shadows(rt, &light_ray, tmp))
// 		{
// 			rt->angle = vectordot(&light_vec, &normal, 0);
// 			color(rt, rt->co[cobj].color.red, rt->co[cobj].color.green,
// 					rt->co[cobj].color.blue);
// 		}
// 	}
// }
