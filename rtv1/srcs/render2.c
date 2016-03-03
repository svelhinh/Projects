/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/03 17:12:50 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/* Subtract two vectors and return the resulting vector */

t_vector3d	vectorsub(t_vector3d *v1, t_vector3d *v2)
{
	t_vector3d result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

/* Multiply two vectors and return the resulting scalar product */

float	vectordot(t_vector3d *v1, t_vector3d *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

int		sphere(t_rt *rt)
{
	float		a;
	float		b;
	float		c;
	float		discr;
	t_vector3d	dist;

	a = vectordot(&rt->vdir, &rt->vdir);
	dist = vectorsub(&rt->campos, &rt->sphere);
	b = 2 * vectordot(&rt->vdir, &dist);
	c = vectordot(&dist, &dist) - pow(rt->sphereradius, 2);
	discr = pow(b, 2) - 4 * a * c;
	if (discr < 0)
		return (0);
	else
		return (1);
}

/*int		plane(t_rt *rt)
{

}*/

void	render(t_rt *rt)
{
	int x;
	int y;
	int hit;
	//int hit2;

	rt->plane.x = SW / 2;
	rt->plane.y = 0;
	rt->plane.z = 0;
	rt->sphere.x = SW / 2;
	rt->sphere.y = SH / 2;
	rt->sphere.z = 20;
	rt->sphereradius = 200;
	rt->vdir.x = 0;
	rt->vdir.y = 0;
	rt->vdir.z = 1;
	rt->campos.z = 0;
	y = 0;
	while (y < SH)
	{
		rt->campos.y = y;
		x = 0;
		while (x < SW)
		{
			rt->campos.x = x;
			hit = sphere(rt);
			//hit2 = plane(rt);
			if (hit)
				mlx_pixel_put_to_image(0xffffff, rt, x, y);
			/*else if (hit2)
				mlx_pixel_put_to_image(0xffffff, rt, x, y);*/
			else
				mlx_pixel_put_to_image(0, rt, x, y);
			x++;
		}
		y++;
	}
}
