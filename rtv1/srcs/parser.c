/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:12:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/31 12:39:52 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	background_color(char *color, t_rt *rt)
{
	int i;

	i = 0;
	if (!color || ft_strlen(color) > 6)
		ft_exit("\033[31mBad format for background_color\n");
	while (color[i])
	{
		if (color[i] < '0' || (color[i] > '9' && color[i] < 'A')
				|| (color[i] > 'F' && color[i] < 'a') || color[i] > 'f')
			ft_exit("\033[31mBad format for background_color\n");
		i++;
	}
	rt->background_color = ft_atoi_base(color, 16);
	ft_strdel(&color);
}

static void	objects(char *object, t_rt *rt, int fd)
{
	if (!ft_strcmp(object, "camera"))
		parsing_camera(fd, rt);
	else if (!ft_strcmp(object, "light"))
		parsing_light(fd, rt);
	else if (!ft_strcmp(object, "sphere"))
		parsing_sphere(fd, rt);
	else if (!ft_strcmp(object, "plane"))
		parsing_plane(fd, rt);
	else if (!ft_strcmp(object, "cylinder"))
		parsing_cylinder(fd, rt);
	else if (!ft_strcmp(object, "cone"))
		parsing_cone(fd, rt);
	else
		ft_exit("\033[31mA defined object doesn't exit\n");
}

static void	resolution(float width, float height, t_rt *rt)
{
	if (width < 7680 && width > 0)
		rt->w = width;
	else
		ft_exit("\033[31mWidth too large\n");
	if (height < 4320 && height > 0)
		rt->h = height;
	else
		ft_exit("\033[31mHeight too large\n");
}

void		global_parser(char *file, t_rt *rt)
{
	int		fd;
	char	*line;
	char	**line2;

	init_all(file, rt);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit("\033[31mThis scene doesn't exist\n");
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0])
		{
			line2 = ft_strsplit(line, ' ');
			if (!ft_strcmp(line2[0], "background_color"))
				background_color(line2[2], rt);
			else if (!ft_strcmp(line2[0], "resolution"))
				resolution(ft_atof(line2[2]), ft_atof(line2[3]), rt);
			else if (!ft_strcmp(line2[0], "object"))
				objects(line2[2], rt, fd);
			line2_free(line2);
		}
		ft_strdel(&line);
	}
	(close(fd) == -1) ? (ft_exit("\033[31mThis scene failed to close")) : (0);
}
