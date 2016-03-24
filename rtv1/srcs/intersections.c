/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:41:50 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/24 11:51:17 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char	*intersect_sphere(char *object)
{
	if (ft_strcmp(object, "sphere"))
	{
		(object) ? (ft_strdel(&object)) : (0);
		object = ft_strdup("sphere");
	}
	return (object);
}

static char	*intersect_plane(char *object)
{
	if (ft_strcmp(object, "plane"))
	{
		(object) ? (ft_strdel(&object)) : (0);
		object = ft_strdup("plane");
	}
	return (object);
}

static char	*intersect_cylinder(char *object)
{
	if (ft_strcmp(object, "cylinder"))
	{
		(object) ? (ft_strdel(&object)) : (0);
		object = ft_strdup("cylinder");
	}
	return (object);
}

static char	*intersect_cone(char *object)
{
	if (ft_strcmp(object, "cone"))
	{
		(object) ? (ft_strdel(&object)) : (0);
		object = ft_strdup("cone");
	}
	return (object);
}

char		*intersect(t_rt *rt, int *currentobj, char *object)
{
	int			i;
	float		t;
	int			imax;
	float		tmp;

	i = 0;
	t = 200000;
	imax = (rt->nbp > rt->nbs) ? (rt->nbp) : (rt->nbs);
	imax = (rt->nbc > imax) ? (rt->nbc) : (imax);
	imax = (rt->nbco > imax) ? (rt->nbco) : (imax);
	while (i < imax)
	{
		if (i < rt->nbs && sphere(&rt->r, &rt->s[i], &t))
		{
			*currentobj = i;
			object = intersect_sphere(object);
		}
		if (i < rt->nbp && plane(&rt->r, &rt->p[i], &t))
		{
			*currentobj = i;
			object = intersect_plane(object);
		}
		if (i < rt->nbc && cylinder(&rt->r, &rt->c[i], &t))
		{
			*currentobj = i;
			object = intersect_cylinder(object);
		}
		if (i < rt->nbco && cone(&rt->r, &rt->co[i], &t))
		{
			*currentobj = i;
			object = intersect_cone(object);
		}
		i++;
	}
	if (*currentobj != -1)
	{
		tmp = 0;
		if (!ft_strcmp(object, "plane"))
			light_plane(rt, t, tmp, *currentobj);
		else if (!ft_strcmp(object, "cylinder"))
			light_cylinder(rt, t, tmp, *currentobj);
		else if (!ft_strcmp(object, "cone"))
			light_cone(rt, t, tmp, *currentobj);
		else if (!ft_strcmp(object, "sphere"))
			light_sphere(rt, t, tmp, *currentobj);
	}
	return (object);
}
