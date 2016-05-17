/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:28:55 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/17 17:55:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	background_color(char *color, t_env *rt)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(color, ' ');
	if (!ft_atof(tab[0]) || !ft_atof(tab[1]) || !ft_atof(tab[2]))
		ft_exit("\033[31mBackground_color parameters missing\n");
	if (ft_atof(tab[0]) <= 0 || ft_atof(tab[0]) >= 1 || ft_atof(tab[1]) <= 0 ||
		ft_atof(tab[1]) >= 1 || ft_atof(tab[2]) <= 0 || ft_atof(tab[2]) >= 1)
		ft_exit("\033[31mBackground_color parameters must be between 0 and 1\n");
	rt->bg_color.r = ft_atof(tab[0]);
	rt->bg_color.g = ft_atof(tab[1]);
	rt->bg_color.b = ft_atof(tab[2]);
}

static void	objects(char *object, t_env *rt, int fd)
{
	if (!ft_strcmp(object, "camera"))
		parsing_camera(fd, rt);
	else if (!ft_strcmp(object, "light"))
		parsing_light(fd, rt);
	else if (!ft_strcmp(object, "sphere") ||
		!ft_strcmp(object, "plane") || !ft_strcmp(object, "cylinder") ||
		!ft_strcmp(object, "cone") || !ft_strcmp(object, "limited_sphere") ||
		!ft_strcmp(object, "limited_cylinder"))
		parsing_objects(fd, object, rt);
	else
		ft_exit("\033[31mA defined object was not found\n");
}

static void	resolution(float width, float height, t_env *rt)
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

static void	parsing(char **tab, t_env *rt, int fd)
{
	if (!ft_strcmp(tab[0], "background_color"))
		background_color(tab[2], rt);
	else if (!ft_strcmp(tab[0], "resolution"))
		(tab[2] && tab[3]) ? (resolution(ft_atof(tab[2]),
					ft_atof(tab[3]), rt)) :
			(ft_exit("\033[31mParameter missing for resolution\n"));
	else if (!ft_strcmp(tab[0], "object"))
		objects(tab[2], rt, fd);
	else if (!ft_strcmp(tab[0], "reflections"))
	{
		if (ft_atoi(tab[2]) >= 0 && ft_atoi(tab[2]) <= 15)
			rt->max_reflect = ft_atoi(tab[2]);
		else
			ft_exit("\033[31mReflections must be between 0 and 15\n");
	}
	else if (!ft_strcmp(tab[0], "refractions"))
	{
		if (ft_atoi(tab[2]) >= 0 && ft_atoi(tab[2]) <= 15)
			rt->max_refract = ft_atoi(tab[2]);
		else
			ft_exit("\033[31mRefractions must be between 0 and 15\n");
	}
	tab_free(tab);
}

void		global_parser(char *file, t_env *rt)
{
	int		fd;
	char	*line;
	char	**tab;

	rt->i_obj = 0;
	rt->i_light = 0;
	init_all(file, rt);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit("\033[31mThis scene doesn't exist\n");
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0])
		{
			tab = ft_strsplit(line, ' ');
			parsing(tab, rt, fd);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	(close(fd) == -1) ? (ft_exit("\033[31mThis scene failed to close")) : (0);
}
