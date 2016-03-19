/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 11:26:59 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/19 14:58:44 by svelhinh         ###   ########.fr       */
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
	t_vector3d		light_vec;		// Vecteur lumiere
	t_vector3d		inter;			// Point d'intersection
	t_vector3d		normal;			// Normale du vecteur directionnel du rayon
	//t_ray			light_ray;
	float			light_dist;		// Distance de la lumiere au point d'intersection
	float			angle;			// Angle entre le vecteur directionnel du rayon et celui de la lumiere
	(void)tmp;

	// Calcul point d'intersection
	inter.x = rt->r.start.x + rt->r.dir.x * t;
	inter.y = rt->r.start.y + rt->r.dir.y * t;
	inter.z = rt->r.start.z + rt->r.dir.z * t;
	// Calcul vecteur lumiere inter - rt->light.pos
	light_vec = vectorsub(&inter, &rt->light.pos, 0);
	// Normalisation du vecteur directionnel de la lumiere
	light_dist = sqrt(pow(light_vec.x, 2) + pow(light_vec.y, 2) + pow(light_vec.z, 2));
	light_vec.x /= light_dist;
	light_vec.y /= light_dist;
	light_vec.z /= light_dist;
	// Normalisation du vecteur directionnel du rayon
	normal.x = rt->r.dir.x / t;
	normal.y = rt->r.dir.y / t;
	normal.z = rt->r.dir.z / t;
	//light_ray.dir = vectorscale(1 / sqrt(vectordot(&light_vec, &light_vec, 0)), &light_vec);
	// Calcul de l'angle
	angle = vectordot(&light_vec, &normal, 0);
	if (angle > 0)
	{
		// Couleurs
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
			tmp = vectordot(&light_vec, &light_vec, 0);
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
