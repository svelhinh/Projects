/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:19:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/01 19:04:19 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	parsing_data(int r, int g, int b, int endian)
{
	unsigned int	rgb;
	char			*tmp;
	char			*rgb2;
	char			*r2;
	char			*g2;
	char			*b2;

	r2 = ft_itoa_base(r, 16);
	g2 = ft_itoa_base(g, 16);
	b2 = ft_itoa_base(b, 16);
	if (r < 16)
	{

		tmp = ft_strdup(r2);
		ft_strdel(&r2);
		r2 = ft_strjoin("0", tmp);
		ft_strdel(&tmp);
	}
	if (g < 16)
	{

		tmp = ft_strdup(g2);
		ft_strdel(&g2);
		g2 = ft_strjoin("0", tmp);
		ft_strdel(&tmp);
	}
	if (b < 16)
	{

		tmp = ft_strdup(b2);
		ft_strdel(&b2);
		b2 = ft_strjoin("0", tmp);
		ft_strdel(&tmp);
	}
	rgb2 = ft_strjoin((endian) ? (r2) : (b2), g2);
	ft_strdel((endian) ? (&r2) : (&b2));
	ft_strdel(&g2);
	tmp = ft_strdup(rgb2);
	ft_strdel(&rgb2);
	rgb2 = ft_strjoin(tmp, (endian) ? (b2) : (r2));
	ft_strdel((endian) ? (&b2) : (&r2));
	ft_strdel(&tmp);
	rgb = ft_atoi_base(rgb2, 16);
	ft_strdel(&rgb2);
	return (rgb);
}

static void	load_tex2(t_ray *r, int tex, char *s)
{
	void			*img;
	unsigned char	*data;
	int				x;
	int				x2;

	img = mlx_xpm_file_to_image(r->mlx, s, &r->w, &r->h);
	data = (unsigned char *)mlx_get_data_addr(img, &r->bpp, &r->size_line,
			&r->endian);
	x = 0;
	x2 = 0;
	if (!(r->texture[tex] = (int *)malloc(sizeof(int) * r->w * r->h)))
		ft_exit("malloc() texture[y] in load_tex() failed");
	while (x2 < r->w * r->h)
	{
		r->texture[tex][x2] = parsing_data(data[x], data[x + 1], data[x + 2],
				r->endian);
		x2++;
		x += (r->bpp / 8);
	}
}

void		load_tex(t_ray *r)
{
	int tex;

	tex = 3;
	if (!(r->texture = (int **)malloc(sizeof(int *) * tex)))
		ft_exit("malloc() texture[y] in load_tex() failed");
	load_tex2(r, 0, "textures/stone.xpm");
	load_tex2(r, 1, "textures/steel.xpm");
	load_tex2(r, 2, "textures/hitler.xpm");
}
