/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/11 11:14:27 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	e;
	t_fdf	v;

	if (ac == 7)
	{
		v.nbn = 1;
		v.width = 2000;
		v.height = 1300;
		v.map = read_map(av[1], &v.nbl, &v.nbn);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, v.width, v.height, "42");
		v.zoom = 0.3;
		v.alti = 0.7 * v.zoom;
		v.av = av;
		put_lines1(e, v, v.alti);
		put_lines2(e, v, v.alti);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_loop(e.mlx);
	}
	else if (ac < 7)
		ft_exit("Pas assez de parametres");
	else
		ft_exit("Trop de parametres");
	return (0);
}
