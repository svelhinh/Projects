/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:42:33 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/18 11:16:44 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parsing_sphere(int fd, t_rt *rt)
{
	static int	i;
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			break ;
		line2 = ft_strsplit(line, ' ');
		if (!ft_strcmp(line2[0], "x_pos"))
			rt->s[i].pos.x = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "y_pos"))
			rt->s[i].pos.y = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "z_pos"))
			rt->s[i].pos.z = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "radius"))
			rt->s[i].radius = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "color"))
		{
			rt->s[i].color.red = ft_atof(line2[2]);
			rt->s[i].color.green = ft_atof(line2[3]);
			rt->s[i].color.blue = ft_atof(line2[4]);
		}
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

	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			break ;
		line2 = ft_strsplit(line, ' ');
		if (!ft_strcmp(line2[0], "x_pos"))
			rt->p[i].pos.x = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "y_pos"))
			rt->p[i].pos.y = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "z_pos"))
			rt->p[i].pos.z = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "color"))
		{
			rt->p[i].color.red = ft_atof(line2[2]);
			rt->p[i].color.green = ft_atof(line2[3]);
			rt->p[i].color.blue = ft_atof(line2[4]);
		}
		line2_free(line2);
		ft_strdel(&line);
	}
	i++;
}

void	parsing_cylinder(int fd, t_rt *rt)
{
	static int	i;
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			break ;
		line2 = ft_strsplit(line, ' ');
		if (!ft_strcmp(line2[0], "x_pos"))
			rt->c[i].pos.x = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "y_pos"))
			rt->c[i].pos.y = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "z_pos"))
			rt->c[i].pos.z = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "radius"))
			rt->c[i].radius = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "color"))
		{
			rt->c[i].color.red = ft_atof(line2[2]);
			rt->c[i].color.green = ft_atof(line2[3]);
			rt->c[i].color.blue = ft_atof(line2[4]);
		}
		line2_free(line2);
		ft_strdel(&line);
	}
	i++;
}

void	parsing_cone(int fd, t_rt *rt)
{
	static int	i;
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			break ;
		line2 = ft_strsplit(line, ' ');
		if (!ft_strcmp(line2[0], "x_pos"))
			rt->co[i].pos.x = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "y_pos"))
			rt->co[i].pos.y = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "z_pos"))
			rt->co[i].pos.z = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "axis"))
			rt->co[i].axis = line2[2][0];
		else if (!ft_strcmp(line2[0], "radius"))
			rt->co[i].radius = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "color"))
		{
			rt->co[i].color.red = ft_atof(line2[2]);
			rt->co[i].color.green = ft_atof(line2[3]);
			rt->co[i].color.blue = ft_atof(line2[4]);
		}
		line2_free(line2);
		ft_strdel(&line);
	}
	i++;
}
