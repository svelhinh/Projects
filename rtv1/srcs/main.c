/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:45:22 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/04 12:43:30 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_exit(char *s)
{
	ft_putstr_fd(s, 2);
	exit(0);
}

void	mlx_pixel_put_to_image(int color, t_rt *v, int x, int y)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	if (x < SW && x > 0 && y < SH && y > 0)
	{
		if (!v->endian)
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
		v->data[y * v->size_line + x * v->bpp / 8] = r;
		v->data[y * v->size_line + x * v->bpp / 8 + 1] = g;
		v->data[y * v->size_line + x * v->bpp / 8 + 2] = b;
	}
}

int		main(int ac, char **av)
{
	t_rt rt;

	if (ac != 2)
	{
		ft_putcolor("light red");
		(ac == 2) ? (ft_exit("Too many parameters")) :
			(ft_exit("Not enough parameters"));
	}
	(!(rt.mlx = mlx_init())) ? (ft_exit("mlx_init() failed in main()")) : (0);
	if (!(rt.win = mlx_new_window(rt.mlx, SW, SH, "RTV1")))
		ft_exit("mlx_new_window() in main() failed");
	parsing_file(av[1], &rt);
	mlx_hook(rt.win, 2, (1L << 0), key_press, &rt);
	mlx_hook(rt.win, 3, (1L << 1), key_release, &rt);
	expose(&rt);
	mlx_loop(rt.mlx);
	return (0);
}
