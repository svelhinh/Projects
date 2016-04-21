/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:29:15 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/20 15:52:28 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parsing_color(t_rt *rt, int j, int i, char **line2)
{
	check_color(ft_atof(line2[2]), ft_atof(line2[3]), ft_atof(line2[4]));
	if (j == 's')
	{
		rt->s[i].color.r = ft_atof(line2[2]);
		rt->s[i].color.g = ft_atof(line2[3]);
		rt->s[i].color.b = ft_atof(line2[4]);
	}
	else if (j == 'p')
	{
		rt->p[i].color.r = ft_atof(line2[2]);
		rt->p[i].color.g = ft_atof(line2[3]);
		rt->p[i].color.b = ft_atof(line2[4]);
	}
	else if (j == 'c')
	{
		rt->c[i].color.r = ft_atof(line2[2]);
		rt->c[i].color.g = ft_atof(line2[3]);
		rt->c[i].color.b = ft_atof(line2[4]);
	}
	else if (j == 'o')
	{
		rt->co[i].color.r = ft_atof(line2[2]);
		rt->co[i].color.g = ft_atof(line2[3]);
		rt->co[i].color.b = ft_atof(line2[4]);
	}
}

void	parsing_sphere(int fd, t_rt *rt)
{
	static int	i;
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line) > 0 && line[0])
	{
		line2 = ft_strsplit(line, ' ');
		if (!line2[2])
			ft_exit("\033[31mMissing parameter for a sphere object\n");
		if (!ft_strcmp(line2[0], "pos"))
		{
			missing_parameter(line2);
			rt->s[i].pos.x = -ft_atof(line2[2]);
			rt->s[i].pos.y = -ft_atof(line2[3]);
			rt->s[i].pos.z = ft_atof(line2[4]);
		}
		else if (!ft_strcmp(line2[0], "radius"))
			(ft_atof(line2[2]) > 0) ? (rt->s[i].radius = ft_atof(line2[2])) :
				(ft_exit("\033[31mSphere radius must be greather than 0\n"));
		else if (!ft_strcmp(line2[0], "color"))
			parsing_color(rt, 's', i, line2);
		line2_free(line2);
		ft_strdel(&line);
	}
	i++;
}

void	parsing_plane(int fd, t_rt *rt)
{
	static int	i;
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line) > 0 && line[0])
	{
		line2 = ft_strsplit(line, ' ');
		missing_parameter(line2);
		if (!ft_strcmp(line2[0], "norm"))
		{
			if (!line2[5])
				ft_exit("\033[31mMissing parameter for a plane object\n");
			rt->p[i].norm.x = ft_atof(line2[2]);
			rt->p[i].norm.y = -ft_atof(line2[3]);
			rt->p[i].norm.z = ft_atof(line2[4]);
			rt->p[i].height = ft_atof(line2[5]);
		}
		// else if (!ft_strcmp(line2[0], "rot"))
			// parsing_rotations(rt, 'p', i, line2);
		else if (!ft_strcmp(line2[0], "color"))
			parsing_color(rt, 'p', i, line2);
		line2_free(line2);
		ft_strdel(&line);
	}
	i++;
}
