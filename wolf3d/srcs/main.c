/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:19:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/05 13:41:22 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_exit(char *s)
{
	perror(s);
	exit(0);
}

int			main(int ac, char **av)
{
	t_ray	r;

	r.i = 0;
	r.lvl = check_param(ac, av);
	r.nb_lvl = check_lvl(r.lvl);
	if (r.nb_lvl == -1)
		ft_exit("Bad file name, please name your files lvl[number] ");
	(!(r.mlx = mlx_init())) ? (ft_exit("mlx_init() failed in main()")) : (0);
	if (!(r.win = mlx_new_window(r.mlx, SWIDTH, SHEIGHT, r.lvl)))
		ft_exit("mlx_new_window failed in main()");
	r.map = parser(r.lvl);
	load_tex(&r);
	mlx_hook(r.win, 2, (1L << 0), &key_press, &r);
	mlx_hook(r.win, 3, (1L << 1), &key_release, &r);
	mlx_loop_hook(r.mlx, &expose, &r);
	mlx_loop(r.mlx);
	return (0);
}
