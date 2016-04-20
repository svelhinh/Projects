/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cylinder_cone.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:27:31 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/20 15:52:16 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	parsing_cylinder2(t_rt *rt, char **line2, int i)
{
	if (!ft_strcmp(line2[0], "pos"))
	{
		missing_parameter(line2);
		rt->c[i].start.x = ft_atof(line2[2]);
		rt->c[i].start.y = ft_atof(line2[3]);
		rt->c[i].start.z = ft_atof(line2[4]);
	}
	else if (!ft_strcmp(line2[0], "rot"))
	{
		missing_parameter(line2);
		parsing_rotations(rt, 'c', i, line2);
	}
	else if (!ft_strcmp(line2[0], "radius"))
		(ft_atof(line2[2]) > 0) ? (rt->c[i].radius = ft_atof(line2[2])) :
		(ft_exit("\033[31mCylinder radius must be greather than 0\n"));
	else if (!ft_strcmp(line2[0], "color"))
	{
		missing_parameter(line2);
		parsing_color(rt, 'c', i, line2);
	}
}

void		parsing_cylinder(int fd, t_rt *rt)
{
	static int	i;
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line) > 0 && line[0])
	{
		line2 = ft_strsplit(line, ' ');
		if (!line2[2])
			ft_exit("\033[31mMissing parameter for a cylinder object\n");
		if (!ft_strcmp(line2[0], "vec"))
		{
			missing_parameter(line2);
			rt->c[i].vec.x = ft_atof(line2[2]);
			rt->c[i].vec.y = ft_atof(line2[3]);
			rt->c[i].vec.z = ft_atof(line2[4]);
		}
		parsing_cylinder2(rt, line2, i);
		line2_free(line2);
		ft_strdel(&line);
	}
	i++;
}

static void	parsing_cone2(t_rt *rt, char **line2, int i)
{
	if (!ft_strcmp(line2[0], "rot"))
	{
		missing_parameter(line2);
		parsing_rotations(rt, 'o', i, line2);
	}
	else if (!ft_strcmp(line2[0], "radius"))
		(ft_atof(line2[2]) >= 0) ? (rt->co[i].radius = ft_atof(line2[2])) :
		(ft_exit("\033[31mCone radius must be greather or equal to 0\n"));
	else if (!ft_strcmp(line2[0], "color"))
	{
		missing_parameter(line2);
		parsing_color(rt, 'o', i, line2);
	}
}

void		parsing_cone(int fd, t_rt *rt)
{
	static int	i;
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line) > 0 && line[0])
	{
		line2 = ft_strsplit(line, ' ');
		if (!line2[2])
			ft_exit("\033[31mMissing parameter for a cone object\n");
		if (!ft_strcmp(line2[0], "pos"))
		{
			missing_parameter(line2);
			rt->co[i].pos.x = ft_atof(line2[2]);
			rt->co[i].pos.y = ft_atof(line2[3]);
			rt->co[i].pos.z = ft_atof(line2[4]);
		}
		parsing_cone2(rt, line2, i);
		line2_free(line2);
		ft_strdel(&line);
	}
	i++;
}
