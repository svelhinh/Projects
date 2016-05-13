/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limited_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:18:35 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/13 18:19:46 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	distance(double a, double b, double c)
{
	double	disc;
	double	t0;
	double	t1;
	double	tmp;

	disc = pow(b, 2) - 4 * a * c;
	if (disc < 0)
		return (0);
	t0 = (-b - sqrt(disc)) / (2 * a);
	t1 = (-b + sqrt(disc)) / (2 * a);
	tmp = (t0 < t1) ? (t0) : (t1);
	return (tmp);
}

static int		disk_calcul(t_vector r, t_figure d, double *t, t_vector eye)
{
	double		tmp;
	t_vector	inter;

	tmp = -(0 * eye.x - 1 * eye.y + d.center.z * 0 + d.center.y) /
			(0 * r.x - 1 * r.y + 0 * r.z);
	if (tmp < *t && tmp > 0.00001)
	{
	   inter = calcul_ptinter(eye, r, tmp);
	   if ((inter.x - d.center.x) * (inter.x - d.center.x) +
	   (inter.z - d.center.z) * (inter.z - d.center.z) < pow(d.radius, 2))
	   {
		   *t = tmp;
		   return (1);
	   }
	}
	return (0);
}

int				limited_sphere(t_vector r, t_figure s, double *t, t_vector eye, int *disk, int i)
{
	double		a;
	double		b;
	double		c;
	double		tmp;
	t_figure	tmp_1;
	t_vector	inter;

	eye = rotations(eye, s.angle.x, s.angle.y, s.angle.z);
	r = rotations(r, s.angle.x, s.angle.y, s.angle.z);
	s.center = rotations(s.center, s.angle.x, s.angle.y, s.angle.z);
	a = pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2);
	b = 2 * (r.x * (eye.x - s.center.x) + r.y * (eye.y - s.center.y) + r.z *
		(eye.z - s.center.z));
	c = (pow(eye.x - s.center.x, 2) + pow(eye.y - s.center.y, 2) +
		pow(eye.z - s.center.z, 2)) - pow(s.radius, 2);
	tmp = distance(a, b, c);
	inter = calcul_ptinter(eye, r, tmp);
	tmp_1 = s;
	tmp_1.radius = sqrt(s.radius * s.radius - s.separation * s.separation);
	tmp_1.center.y += s.separation;
	if (tmp < *t && tmp > 0.00001)
	{
		if (inter.y <= s.center.y + s.separation)
		{
			*t = tmp;
			return (1);
		}
		if (disk_calcul(r, tmp_1, t, eye))
		{
			*disk = 2;
			return (2);
		}
		// if (i)
			*disk = 0;
	}
	return (0);
}

int			limited_cylinder(t_vector r, t_figure cy, double *t, t_vector eye, int *disk, int i)
{
	double		a;
	double		b;
	double		c;
	double		tmp;
	t_figure	tmp_1;
	t_vector	inter;

	eye = rotations(eye, cy.angle.x, cy.angle.y, cy.angle.z);
	r = rotations(r, cy.angle.x, cy.angle.y, cy.angle.z);
	cy.center = rotations(cy.center, cy.angle.x, cy.angle.y, cy.angle.z);
	a = pow(r.x, 2) + pow(r.z, 2);
	b = 2 * (r.x * (eye.x - cy.center.x) + r.z * (eye.z - cy.center.z));
	c = pow(eye.x - cy.center.x, 2) + pow(eye.z - cy.center.z, 2) -
		pow(cy.radius, 2);
	tmp = distance(a, b, c);
	inter = calcul_ptinter(eye, r, tmp);
	tmp_1 = cy;
	if (tmp < *t && tmp > 0.00001)
	{
		if (inter.y <= cy.center.y + cy.separation && inter.y >= cy.center.y - cy.separation)
		{
			*t = tmp;
			return (1);
		}
		else if (inter.y > cy.center.y + cy.separation)
		{
			tmp_1.center.y += cy.separation;
			*disk = 2;
			if (disk_calcul(r, tmp_1, t, eye))
				return (1);
		}
		else if (inter.y < cy.center.y - cy.separation)
		{
			tmp_1.center.y -= cy.separation;
			*disk = 3;
			if (disk_calcul(r, tmp_1, t, eye))
				return (1);
		}
		// if (i && *disk == 3)
			*disk = 0;
	}
	return (0);
}
