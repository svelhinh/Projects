/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:54:36 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/11 16:58:35 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	init_sphere_tab(char *file, t_rt *rt)
{
	int		fd;
	char	*line;
	int		i;

	rt->nbs = 0;
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit("\033[31mThis scene doesn't exist\n");
	while (get_next_line(fd, &line))
	{
		rt->nbs += (ft_strstr(line, "object : sphere")) ? (1) : (0);
		ft_strdel(&line);
	}
	if (!(rt->s = (t_sphere *)malloc(sizeof(t_sphere) * rt->nbs)))
		ft_exit("malloc of rt->s failed in init_sphere_tab");
	while (i < rt->nbs)
	{
		rt->s[i].pos.x = 0;
		rt->s[i].pos.y = 0;
		rt->s[i].pos.z = 0;
		rt->s[i].radius = 0;
		rt->s[i].color = 0;
		i++;
	}
	(close(fd) == -1) ? (ft_exit("\033[31mThis scene failed to close")) : (0);
}

static void	init_plane_tab(char *file, t_rt *rt)
{
	int		fd;
	char	*line;
	int		i;

	rt->nbp = 0;
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit("\033[31mThis scene doesn't exist\n");
	while (get_next_line(fd, &line))
	{
		rt->nbp += (ft_strstr(line, "object : plane")) ? (1) : (0);
		ft_strdel(&line);
	}
	if (!(rt->p = (t_plane *)malloc(sizeof(t_plane) * rt->nbp)))
		ft_exit("malloc of rt->p failed in init_plane_tab");
	while (i < rt->nbp)
	{
		rt->p[i].pos.x = 0;
		rt->p[i].pos.y = 0;
		rt->p[i].pos.z = 0;
		rt->p[i].color = 0;
		i++;
	}
	(close(fd) == -1) ? (ft_exit("\033[31mThis scene failed to close")) : (0);
}

static void	init_cylinder_tab(char *file, t_rt *rt)
{
	int		fd;
	char	*line;
	int		i;

	rt->nbc = 0;
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit("\033[31mThis scene doesn't exist\n");
	while (get_next_line(fd, &line))
	{
		rt->nbc += (ft_strstr(line, "object : cylinder")) ? (1) : (0);
		ft_strdel(&line);
	}
	if (!(rt->c = (t_cylinder *)malloc(sizeof(t_cylinder) * rt->nbc)))
		ft_exit("malloc of rt->c failed in init_cylinder_tab");
	while (i < rt->nbc)
	{
		rt->c[i].pos.x = 0;
		rt->c[i].pos.y = 0;
		rt->c[i].pos.z = 0;
		rt->c[i].radius = 0;
		rt->c[i].color = 0;
		i++;
	}
	(close(fd) == -1) ? (ft_exit("\033[31mThis scene failed to close")) : (0);
}

void		init_all(char *file, t_rt *rt)
{
	rt->default_color = 0;
	rt->campos.x = 0;
	rt->campos.y = 0;
	rt->campos.z = 0;
	rt->r.dir.x = 0;
	rt->r.dir.y = 0;
	rt->r.dir.z = 0;
	init_sphere_tab(file, rt);
	init_plane_tab(file, rt);
	init_cylinder_tab(file, rt);
}
