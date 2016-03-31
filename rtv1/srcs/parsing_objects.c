/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:42:33 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/31 12:38:32 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	color(t_rt *rt, int j, int i, char **line2)
{
	if (j == 's')
	{
		rt->s[i].color.red = ft_atof(line2[2]);
		rt->s[i].color.green = ft_atof(line2[3]);
		rt->s[i].color.blue = ft_atof(line2[4]);
	}
	else if (j == 'p')
	{
		rt->p[i].color.red = ft_atof(line2[2]);
		rt->p[i].color.green = ft_atof(line2[3]);
		rt->p[i].color.blue = ft_atof(line2[4]);
	}
	else if (j == 'c')
	{
		rt->c[i].color.red = ft_atof(line2[2]);
		rt->c[i].color.green = ft_atof(line2[3]);
		rt->c[i].color.blue = ft_atof(line2[4]);
	}
	else if (j == 'o')
	{
		rt->co[i].color.red = ft_atof(line2[2]);
		rt->co[i].color.green = ft_atof(line2[3]);
		rt->co[i].color.blue = ft_atof(line2[4]);
	}
}

void		parsing_sphere(int fd, t_rt *rt)
{
	static int	i;
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line) && line[0])
	{
		line2 = ft_strsplit(line, ' ');
		if (!ft_strcmp(line2[0], "pos"))
		{
			rt->s[i].pos.x = ft_atof(line2[2]);
			rt->s[i].pos.y = ft_atof(line2[3]);
			rt->s[i].pos.z = ft_atof(line2[4]);
		}
		else if (!ft_strcmp(line2[0], "radius"))
			rt->s[i].radius = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "color"))
			color(rt, 's', i, line2);
		line2_free(line2);
		ft_strdel(&line);
	}
	i++;
}

void		parsing_plane(int fd, t_rt *rt)
{
	static int	i;
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line) && line[0])
	{
		line2 = ft_strsplit(line, ' ');
		if (!ft_strcmp(line2[0], "norm"))
		{
			rt->p[i].norm.x = ft_atof(line2[2]);
			rt->p[i].norm.y = ft_atof(line2[3]);
			rt->p[i].norm.z = ft_atof(line2[4]);
			rt->p[i].height = ft_atof(line2[5]);
		}
		else if (!ft_strcmp(line2[0], "rot"))
			parsing_rotations(rt, 'p', i, line2);
		else if (!ft_strcmp(line2[0], "color"))
			color(rt, 'p', i, line2);
		line2_free(line2);
		ft_strdel(&line);
	}
	i++;
}

void		parsing_cylinder(int fd, t_rt *rt)
{
	static int	i;
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line) && line[0])
	{
		line2 = ft_strsplit(line, ' ');
		if (!ft_strcmp(line2[0], "vec"))
		{
			rt->c[i].vec.x = ft_atof(line2[2]);
			rt->c[i].vec.y = ft_atof(line2[3]);
			rt->c[i].vec.z = ft_atof(line2[4]);
		}
		else if (!ft_strcmp(line2[0], "pos"))
		{
			rt->c[i].start.x = ft_atof(line2[2]);
			rt->c[i].start.y = ft_atof(line2[3]);
			rt->c[i].start.z = ft_atof(line2[4]);
		}
		else if (!ft_strcmp(line2[0], "rot"))
			parsing_rotations(rt, 'c', i, line2);
		else if (!ft_strcmp(line2[0], "radius"))
			rt->c[i].radius = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "color"))
			color(rt, 'c', i, line2);
		line2_free(line2);
		ft_strdel(&line);
	}
	i++;
}

void		parsing_cone(int fd, t_rt *rt)
{
	static int	i;
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line) && line[0])
	{
		line2 = ft_strsplit(line, ' ');
		if (!ft_strcmp(line2[0], "pos"))
		{
			rt->co[i].pos.x = ft_atof(line2[2]);
			rt->co[i].pos.y = ft_atof(line2[3]);
			rt->co[i].pos.z = ft_atof(line2[4]);
		}
		else if (!ft_strcmp(line2[0], "rot"))
			parsing_rotations(rt, 'o', i, line2);
		else if (!ft_strcmp(line2[0], "radius"))
			rt->co[i].radius = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "color"))
			color(rt, 'o', i, line2);
		line2_free(line2);
		ft_strdel(&line);
	}
	i++;
}
