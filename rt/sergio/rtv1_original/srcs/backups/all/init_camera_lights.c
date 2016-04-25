/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera_lights.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:16:17 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/18 10:44:07 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_light(char *file, t_rt *rt)
{
	int		fd;
	char	*line;
	int		i;

	rt->nbl = 0;
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit("\033[31mThis scene doesn't exist\n");
	while (get_next_line(fd, &line))
	{
		rt->nbl += (!ft_strcmp(line, "object : light")) ? (1) : (0);
		ft_strdel(&line);
	}
	if (!(rt->light = (t_light *)malloc(sizeof(t_light) * rt->nbl)))
		ft_exit("malloc of rt->light failed in init_light_tab");
	while (i < rt->nbl)
	{
		rt->light[i].pos.x = 0;
		rt->light[i].pos.y = 0;
		rt->light[i].pos.z = 0;
		rt->light[i].intensity.red = 0;
		rt->light[i].intensity.green = 0;
		rt->light[i].intensity.blue = 0;
		i++;
	}
	(close(fd) == -1) ? (ft_exit("\033[31mThis scene failed to close")) : (0);
}

void	init_camera(t_rt *rt)
{
	rt->campos.x = 0;
	rt->campos.y = 0;
	rt->campos.z = 0;
	rt->r.dir.x = 0;
	rt->r.dir.y = 0;
	rt->r.dir.z = 0;
}
