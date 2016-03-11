/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:12:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/11 12:58:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	default_color(char *color, t_rt *rt)
{
	int color2;
	int i;

	i = 0;
	if (!color || ft_strlen(color) > 6)
		ft_exit("\033[31mBad format for default_color\n");
	while (color[i])
	{
		if (color[i] < '0' || (color[i] > '9' && color[i] < 'A')
				|| (color[i] > 'F' && color[i] < 'a') || color[i] > 'f')
			ft_exit("\033[31mBad format for default_color\n");
		i++;
	}
	color2 = ft_atoi_base(color, 16);
	ft_strdel(&color);
	rt->default_color = color2;
}

static void	objects(char *object, t_rt *rt, int fd)
{
	if (ft_strstr(object, "camera"))
		camera_init(fd, rt);
	else if (ft_strstr(object, "sphere"))
		sphere_init(fd, rt);
	else if (ft_strstr(object, "plane"))
		plane_init(fd, rt);
	else
		ft_exit("\033[31mThis object doesn't exit\n");
}

void		parsing_file(char *file, t_rt *rt)
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
			if (ft_strstr(line2[0], "default_color"))
				default_color(line2[2], rt);
			else if (ft_strstr(line2[0], "object"))
				objects(line2[2], rt, fd);
			line2_free(line2);
		}
		ft_strdel(&line);
	}
}
