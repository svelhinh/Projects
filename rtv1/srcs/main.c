/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:28:45 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/31 15:28:46 by svelhinh         ###   ########.fr       */
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

	if (x < v->w && x > 0 && y < v->h && y > 0)
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
		(ac > 2) ? (ft_exit("\033[31mToo many parameters\n")) :
			(ft_exit("\033[31mNot enough parameters\n"));
	}
	if (av[1][ft_strlen(av[1]) - 3] == '.' && av[1][ft_strlen(av[1]) - 2] == 'r'
			&& av[1][ft_strlen(av[1]) - 1] == 't')
		global_parser(av[1], &rt);
	else
		ft_exit("\033[31mFiles must have .rt extension\n");
	(!(rt.mlx = mlx_init())) ? (ft_exit("mlx_init() failed in main()")) : (0);
	if (!(rt.win = mlx_new_window(rt.mlx, rt.w, rt.h, "RTV1")))
		ft_exit("mlx_new_window() in main() failed");
	mlx_hook(rt.win, 2, (1L << 0), key_press, &rt);
	mlx_hook(rt.win, 3, (1L << 1), key_release, &rt);
	expose(&rt);
	mlx_loop(rt.mlx);
	return (0);
}
