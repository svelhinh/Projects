/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/10 11:43:39 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	e;
	t_fdf	v;
	float	alti;
	int		width;
	int		height;

	(void)ac;
	v.nbn = 1;
	width = 2000;
	height = 1300;
	v.map = read_map(av[1], &v.nbl, &v.nbn);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, width, height, "42");
	v.zoom = 0.1;
	alti = 0.7 * v.zoom;
	put_lines1(e, v, alti);
	put_lines2(e, v, alti);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
