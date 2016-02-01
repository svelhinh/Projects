/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:19:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/01 13:01:25 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_exit(char *s)
{
	perror(s);
	exit(0);
}

char	*check_param(int ac, char **av)
{
	char	*lvl;
	char	*tmp;
	char	*tmp2;
	int		nb_alea;

	if (ac == 1)
	{
		srand(time(NULL));
		nb_alea = rand() % 1;
		tmp = ft_strdup("levels/lvl");
		tmp2 = ft_itoa(nb_alea);
		lvl = ft_strjoin(tmp, tmp2);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
		return (lvl);
	}
	else if (ac == 2)
		return (ft_strjoin("levels/", av[1]));
	else
	{
		ft_putcolor("light red");
		ft_exit("Too many parameters");
	}
	return (NULL);
}

int		parsing_data(char r, char g, char b)
{
	int rgb;
	char *rgb2;
	char *r2;
	char *g2;
	char *b2;

	r2 = ft_itoa_base(b, 16);
	g2 = ft_itoa_base(g, 16);
	b2 = ft_itoa_base(r, 16);
	(r < 16) ? (b2 = ft_strjoin("0", b2)) : (0);
	(g < 16) ? (g2 = ft_strjoin("0", g2)) : (0);
	(b < 16) ? (r2 = ft_strjoin("0", r2)) : (0);
	rgb2 = ft_strjoin(r2, g2);
	rgb2 = ft_strjoin(rgb2, b2);
	rgb = ft_atoi_base(rgb2, 16);
	return (rgb);
}

void	load_tex(t_ray *r)
{
	int x;
	int x2;
	void *img;
	char *data;
	int bpp;
	int endian;
	int size_line;

	img = mlx_xpm_file_to_image(r->mlx, "textures/plafond.xpm", &r->w, &r->h);
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	if (!(r->texture = (int *)malloc(sizeof(int) * r->w * r->h)))
		ft_exit("malloc() texture[y] in load_tex() failed");
	x = 0;
	x2 = 0;
	while (x2 < r->w * r->h)
	{
		r->texture[x2] = parsing_data(data[x], data[x + 1], data[x + 2]);
		x2++;
		x += 4;
	}
}

int		main(int ac, char **av)
{
	t_ray	r;

	r.i = 0;
	r.lvl = check_param(ac, av);
	if (ft_strcmp(r.lvl, "levels/lvl0"))
		ft_exit("Bad file name, please name your files lvl[number] ");
	(!(r.mlx = mlx_init())) ? (ft_exit("mlx_init() failed in main()")) : (0);
	if (!(r.win = mlx_new_window(r.mlx, SWIDTH, SHEIGHT, r.lvl)))
		ft_exit("mlx_new_window failed in main()");
	r.map = parser(r.lvl);
	load_tex(&r);
	mlx_expose_hook(r.win, expose, &r);
	mlx_hook(r.win, 2, 64, key, &r);
	//mlx_key_hook(r.win, key, &r);
	mlx_loop(r.mlx);
	return (0);
}
