/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:28:12 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/20 15:46:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	count_objects(t_rt *rt, char *file)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit("\033[31mThis scene doesn't exist\n");
	while (get_next_line(fd, &line) > 0)
	{
		rt->nbs += (!ft_strcmp(line, "object : sphere")) ? (1) : (0);
		rt->nbp += (!ft_strcmp(line, "object : plane")) ? (1) : (0);
		rt->nbc += (!ft_strcmp(line, "object : cylinder")) ? (1) : (0);
		rt->nbco += (!ft_strcmp(line, "object : cone")) ? (1) : (0);
		ft_strdel(&line);
	}
	(close(fd) == -1) ? (ft_exit("\033[31mThis scene failed to close")) : (0);
}

void	init_sphere(t_rt *rt)
{
	int		i;

	i = 0;
	if (!(rt->s = (t_sphere *)malloc(sizeof(t_sphere) * rt->nbs)))
		ft_exit("malloc of rt->s failed in init_sphere_tab");
	while (i < rt->nbs)
	{
		rt->s[i].pos.x = 0;
		rt->s[i].pos.y = 0;
		rt->s[i].pos.z = 0;
		rt->s[i].radius = 0;
		rt->s[i].color.red = 0;
		rt->s[i].color.green = 0;
		rt->s[i].color.blue = 0;
		i++;
	}
}

void	init_plane(t_rt *rt)
{
	int		i;

	i = 0;
	if (!(rt->p = (t_plane *)malloc(sizeof(t_plane) * rt->nbp)))
		ft_exit("malloc of rt->p failed in init_plane_tab");
	while (i < rt->nbp)
	{
		rt->p[i].norm.x = 0;
		rt->p[i].norm.y = 0;
		rt->p[i].norm.z = 0;
		rt->p[i].rot.x = 0;
		rt->p[i].rot.y = 0;
		rt->p[i].rot.z = 0;
		rt->p[i].color.red = 0;
		rt->p[i].color.green = 0;
		rt->p[i].color.blue = 0;
		rt->p[i].height = 0;
		i++;
	}
}

void	init_cylinder(t_rt *rt)
{
	int		i;

	i = 0;
	if (!(rt->c = (t_cylinder *)malloc(sizeof(t_cylinder) * rt->nbc)))
		ft_exit("malloc of rt->c failed in init_cylinder_tab");
	while (i < rt->nbc)
	{
		rt->c[i].vec.x = 0;
		rt->c[i].vec.y = 0;
		rt->c[i].vec.z = 0;
		rt->c[i].start.x = 0;
		rt->c[i].start.y = 0;
		rt->c[i].start.z = 0;
		rt->c[i].rot.x = 0;
		rt->c[i].rot.y = 0;
		rt->c[i].rot.z = 0;
		rt->c[i].radius = 0;
		rt->c[i].color.red = 0;
		rt->c[i].color.green = 0;
		rt->c[i].color.blue = 0;
		i++;
	}
}

void	init_cone(t_rt *rt)
{
	int		i;

	i = 0;
	if (!(rt->co = (t_cone *)malloc(sizeof(t_cone) * rt->nbco)))
		ft_exit("malloc of rt->co failed in init_cone_tab");
	while (i < rt->nbco)
	{
		rt->co[i].pos.x = 0;
		rt->co[i].pos.y = 0;
		rt->co[i].pos.z = 0;
		rt->co[i].rot.x = 0;
		rt->co[i].rot.y = 0;
		rt->co[i].rot.z = 0;
		rt->co[i].radius = 0;
		rt->co[i].color.red = 0;
		rt->co[i].color.green = 0;
		rt->co[i].color.blue = 0;
		i++;
	}
}
