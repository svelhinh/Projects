/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:12:29 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/09 12:04:26 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	default_color(char *color, t_rt *rt)
{
	int color2;
	int i;

	i = 0;
	while (color[++i])
		if ((!ft_isdigit(color[i]) && (color[i] < 'a' || color[i] > 'f')
				&& (color[i] < 'A' || color[i] > 'F')) || ft_strlen(color) > 6)
			ft_exit("\033[31mBad format for default_color\n");
	color2 = ft_atoi_base(color, 16);
	rt->default_color = color2;
}

void		parsing_file(char *file, t_rt *rt)
{
	int		fd;
	char	*line;
	char	**line2;
	(void)rt;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit("\033[31mThis scene doesn't exist\n");
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\0')
		{
			line2 = ft_strsplit(line, ' ');
			if (ft_strstr(line2[0], "default_color"))
				default_color(line2[2], rt);
		}
		ft_strdel(&line);
	}
}
