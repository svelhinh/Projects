/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:12:58 by svelhinh          #+#    #+#             */
/*   Updated: 2018/06/29 19:14:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	parsing_obj(t_obj *obj, char *obj_file)
{
	FILE	*file;
	char	*line;
	float	*points_tmp;
	int		nb_points_tmp;
	char	**splitted_line;
	int		i;
	int		j;
	int		nb_pts_triangulated;
	int		face;

	points_tmp = NULL;
	nb_points_tmp = 0;
	obj->points = NULL;
	obj->nb_points = 0;
	if (is_dir(obj_file) != 0)
		ft_puterror("you tried to open a directory");
	if ((file = fopen(obj_file, "r")) == NULL)
		ft_puterror("open file failed");
	while (get_next_line(fileno(file), &line))
	{
		if (!strcmp(line, ""))
			continue;
		splitted_line = ft_strsplit(line, ' ');
		if (splitted_line[1] != NULL && splitted_line[2] != NULL &&
			splitted_line[3] != NULL)
		{
			if (!strcmp(splitted_line[0], "v"))
			{
				nb_points_tmp += 3;
				if ((points_tmp = (float *)realloc(points_tmp, sizeof(float) *
					nb_points_tmp)) == NULL)
					ft_puterror("malloc failed");
				points_tmp[nb_points_tmp - 3] = (float)atof(splitted_line[1]);
				points_tmp[nb_points_tmp - 2] = (float)atof(splitted_line[2]);
				points_tmp[nb_points_tmp - 1] = (float)atof(splitted_line[3]);
			}
			else if (!strcmp(splitted_line[0], "f"))
			{
				i = 1;
				j = 1;
				nb_pts_triangulated = 0;
				while (splitted_line[i] != NULL)
				{
					if (i != 1 && i == j)
					{
						i++;
						continue;
					}
					obj->nb_points += 3;
					if ((obj->points = (float *)realloc(obj->points,
						sizeof(float) * obj->nb_points)) == NULL)
						ft_puterror("malloc failed");
					face = (atoi(splitted_line[i]) - 1) * 3;
					obj->points[obj->nb_points - 3] = points_tmp[face];
					obj->points[obj->nb_points - 2] = points_tmp[face + 1];
					obj->points[obj->nb_points - 1] = points_tmp[face + 2];
					i++;
					nb_pts_triangulated++;
					if (nb_pts_triangulated == 3 && splitted_line[i] != NULL)
					{
						i = 1;
						j++;
						nb_pts_triangulated = 0;
					}
				}
			}
		}
	}
	obj->nb_points /= 3;
	fclose(file);
}
