/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:19:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/10 13:38:53 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_exit(char *s)
{
	perror(s);
	exit(0);
}

void		main2(t_ray r)
{
	r.time = clock();
	r.time_s = 0;
	ft_empty(&r, 2);
	r.i = 0;
	r.nb_lvl = check_lvl(r.lvl);
	r.map = parser(r.lvl);
	load_tex(&r);
	mlx_hook(r.win, 2, (1L << 0), key_press, &r);
	mlx_hook(r.win, 3, (1L << 1), key_release, &r);
	mlx_loop_hook(r.mlx, expose, &r);
	mlx_loop(r.mlx);
}

int			main(int ac, char **av)
{
	t_ray m;

	(void)av;
	if (ac != 1)
	{
		ft_putcolor("light red");
		ft_exit("Too many parameters");
	}
	(!(m.mlx = mlx_init())) ? (ft_exit("mlx_init() failed in main()")) : (0);
	m.sw = 1024;
	m.sh = 768;
	principal_menu(&m, 0);
	return (0);
}
