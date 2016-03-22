/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 11:26:59 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/22 12:09:40 by svelhinh         ###   ########.fr       */
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
			//printf("tmp = %f\n", tmp);
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
	/*t_vector3d		light_vec;		// Vecteur de la lumiere
	t_vector3d		inter;			// Point d'intersection
	float			angle;			// angle entre les 2 rayons (camera et lumiere)
	float			inter_dist;		// variable utilise pour normaliser le vecteur au point d'intersection
	float			light_dist;		// distance de la lumiere au point d'intersection

	(void)tmp;
	//printf("%f\n", t);
	//printf("start.x : %f\nstart.y : %f\nstart.z : %f\n\n", rt->r.dir.x, rt->r.dir.y, rt->r.dir.z);
	inter.x = rt->r.start.x + rt->r.dir.x * t;		// Calcul du point d'intersection
	inter.y = rt->r.start.y + rt->r.dir.y * t;
	inter.z = rt->r.start.z + rt->r.dir.z * t;
	light_vec = vectorsub(&rt->light.pos, &inter, 0);	// Calcul du vecteur de la lumiere
	//printf("light_dist : %f\n\n", light_dist);
	light_dist = sqrt(pow(light_vec.x, 2) + pow(light_vec.y, 2) + pow(light_vec.z, 2));		// Normalisation du vecteur de la lumiere
	light_vec.x /= light_dist;
	light_vec.y /= light_dist;
	light_vec.z /= light_dist;
	//printf("light_vec.x : %f\nlight_vec.y : %f\nlight_vec.z : %f\n\n", light_vec.x, light_vec.y, light_vec.z);
	inter_dist = sqrt(pow(inter.x, 2) + pow(inter.y, 2) + pow(inter.z, 2));		// Normalisation du vecteur de l'intersection
	inter.x /= inter_dist;
	inter.y /= inter_dist;
	inter.z /= inter_dist;
	angle = vectordot(&light_vec, &inter, 0);		// Calcul de l'angle
	printf("angle : %f\n", angle);
	if (angle > 0)
	{
		//printf("inter.x : %f\ninter.y : %f\ninter.z : %f\n\n", inter.x, inter.y, inter.z);
		//printf("angle : %f\n", angle);i
		rt->global_color.red += angle * rt->light.intensity.red * rt->p[currentobj].color.red;		// Calcul des couleurs
		rt->global_color.green += angle * rt->light.intensity.green * rt->p[currentobj].color.green;
		rt->global_color.blue += angle * rt->light.intensity.blue * rt->p[currentobj].color.blue;
	}*/
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
			tmp = fabs(sqrt(vectordot(&dist, &dist, 0)));
			if (tmp > 0)
			{
				light_ray.start = newstart;
				light_ray.dir = vectorscale(1 / tmp, &dist);
				tmp = fabs(vectordot(&light_ray.dir, &normal, 0));
				printf("tmp = %f\n", tmp);
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
