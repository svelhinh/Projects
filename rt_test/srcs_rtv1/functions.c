/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:27:55 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/31 15:27:57 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	line2_free(char **line2)
{
	int i;

	i = 0;
	while (line2[i])
	{
		ft_strdel(line2);
		i++;
	}
	free(line2);
	line2 = NULL;
}

void	check_color(float r, float g, float b)
{
	if (r < 0 || r > 1 || g < 0 || g > 1 || b < 0 || b > 1)
		ft_exit("\033[31mColor must be between 0 and 1\n");
}

void	color(t_rt *rt, float red, float green, float blue)
{
	rt->global_color.red += rt->angle * rt->light.intensity.red
		* red;
	rt->global_color.green += rt->angle
		* rt->light.intensity.green * green;
	rt->global_color.blue += rt->angle
		* rt->light.intensity.blue * blue;
}

void	missing_parameter(char **line2)
{
	if (ft_strcmp(line2[1], ":"))
		ft_exit("\033[31mCharacter ':' not found\n");
	if (!line2[2] || !line2[3] || !line2[4])
		ft_exit("\033[31mMissing parameter\n");
}
