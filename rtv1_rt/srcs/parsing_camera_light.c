/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_camera_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:29:03 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/25 15:41:25 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parsing_camera(int fd, t_env *rt)
{
	char *line;
	char **line2;

	while (get_next_line(fd, &line) > 0 && line[0] != '\0')
	{
		line2 = ft_strsplit(line, ' ');
		missing_parameter(line2);
		if (!ft_strcmp(line2[0], "pos"))
		{
			rt->eye.x = ft_atof(line2[2]);
			rt->eye.y = ft_atof(line2[3]);
			rt->eye.z = ft_atof(line2[4]);
		}
		// else if (!ft_strcmp(line2[0], "rot"))
		// {
		// 	rt->rotcam.x = ft_atof(line2[2]);
		// 	rt->rotcam.y = ft_atof(line2[3]);
		// 	rt->rotcam.z = ft_atof(line2[4]);
		// 	rt->r.dir = rotations(rt->r.dir, rt->rotcam.x, rt->rotcam.y,
		// 			rt->rotcam.z);
		// }
		// line2_free(line2);
		ft_strdel(&line);
	}
}

// void	parsing_light(int fd, t_env *rt)
// {
// 	char		*line;
// 	char		**line2;
//
// 	while (get_next_line(fd, &line) > 0 && line[0] != '\0')
// 	{
// 		line2 = ft_strsplit(line, ' ');
// 		missing_parameter(line2);
// 		if (!ft_strcmp(line2[0], "pos"))
// 		{
// 			rt->light.pos.x = ft_atof(line2[2]);
// 			rt->light.pos.y = ft_atof(line2[3]);
// 			rt->light.pos.z = ft_atof(line2[4]);
// 		}
// 		else if (!ft_strcmp(line2[0], "color"))
// 		{
// 			check_color(ft_atof(line2[2]), ft_atof(line2[3]),
// 					ft_atof(line2[4]));
// 			rt->light.intensity.r = ft_atof(line2[2]);
// 			rt->light.intensity.g = ft_atof(line2[3]);
// 			rt->light.intensity.b = ft_atof(line2[4]);
// 		}
// 		line2_free(line2);
// 		ft_strdel(&line);
// 	}
// }
