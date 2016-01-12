/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/12 17:34:01 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_fdf	v;

	if (ac == 7)
	{
		v.nbn = 1;
		v.width = 2000;
		v.height = 1300;
		v.zoom = 1;
		v.alti = v.zoom;
		v.y2 = 100;
		v.x2 = 1000;
		v.map = read_map(av[1], &v.nbl, &v.nbn);
		v.mlx = mlx_init();
		v.win = mlx_new_window(v.mlx, v.width, v.height, av[1]);
		v.av = av;
		mlx_expose_hook(v.win, expose_hook, &v);
		mlx_key_hook(v.win, key_hook, &v);
		mlx_mouse_hook(v.win, mouse_hook, &v);
		mlx_loop(v.mlx);
	}
	else if (ac < 7)
		ft_exit("Pas assez de parametres\n");
	else
		ft_exit("Trop de parametres\n");
	return (0);
}
