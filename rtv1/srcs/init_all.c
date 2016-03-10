/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:54:36 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/10 11:29:10 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	init_sphere_tab(char *file, t_rt *rt)
{
	int		fd;
	char	*line;

	rt->nbs = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit("\033[31mThis scene doesn't exist\n");
	while (get_next_line(fd, &line))
	{
		rt->nbs += (ft_strstr(line, "object : sphere")) ? (1) : (0);
		ft_strdel(&line);
	}
	if (!(rt->s = (t_sphere *)malloc(sizeof(t_sphere) * rt->nbs)))
		ft_exit("malloc of rt->s failed in init_sphere_tab");
	close(fd);
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
}
