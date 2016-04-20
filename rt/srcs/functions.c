/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:09:36 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/20 15:09:38 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_exit(char *s)
{
	ft_putendl(s);
	exit(0);
}

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

void	mlx_pixel_put_to_image(int color, t_rt *img, int x, int y)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	if (x < img->w && x > 0 && y < img->h && y > 0)
	{
		if (!img->endian)
		{
			b = (color & 0xFF0000) >> 16;
			r = (color & 0xFF);
		}
		else
		{
			r = (color & 0xFF0000) >> 16;
			b = (color & 0xFF);
		}
		g = (color & 0xFF00) >> 8;
		img->data[y * img->size_line + x * img->bpp / 8] = r;
		img->data[y * img->size_line + x * img->bpp / 8 + 1] = g;
		img->data[y * img->size_line + x * img->bpp / 8 + 2] = b;
	}
}

void	missing_parameter(char **line2)
{
	if (ft_strcmp(line2[1], ":"))
		ft_exit("\033[31mCharacter ':' not found\n");
	if (!line2[2] || !line2[3] || !line2[4])
		ft_exit("\033[31mMissing parameter\n");
}

void	check_color(float r, float g, float b)
{
	if (r < 0 || r > 1 || g < 0 || g > 1 || b < 0 || b > 1)
		ft_exit("\033[31mColor must be between 0 and 1\n");
}
