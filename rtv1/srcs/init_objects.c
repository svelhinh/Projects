/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:42:33 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/09 14:21:12 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	camera_init(int fd, t_rt *rt)
{
	(void)fd;
	(void)rt;
	/*char *line;
	char **line2;

	while (get_next_line(fd, &line))
	{
		line2 = ft_strsplit(line, ' ');
		if (ft_strstr(line2[0], "x_pos"))
			rt->campos.x = 0;
		ft_strdel(&line);
	}*/
}

void	sphere_init(int fd, t_rt *rt)
{
	(void)fd;
	(void)rt;
}

void	plane_init(int fd, t_rt *rt)
{
	(void)fd;
	(void)rt;
}
