/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:19:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/29 18:54:54 by svelhinh         ###   ########.fr       */
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

void	load_tex(t_ray *r)
{
	int w;
	int h;
	void *img;
	//char *data;
	/*int x;
	int y;*/
	/*int xycolor;*/

	if (!(r->texture = (char **)malloc(sizeof(char *) * NTEX)))
		ft_exit("malloc() texture in load_texd_tex() failed");
	if (!(r->texture[0] = (char *)malloc(sizeof(char) * THEIGHT * TWIDTH)))
		ft_exit("malloc() texture[y] in load_tex() failed");
	img = mlx_xpm_file_to_image(r->mlx, "textures/mur2.xpm", &w, &h);
	r->texture[0] = mlx_get_data_addr(img, &r->bpp, &r->size_line, &r->endian);
	/*y = 0;
	  while (y < NTEX)
	  {
	  if (!(r->texture[y] = (char *)malloc(sizeof(char) * THEIGHT * TWIDTH)))
	  ft_exit("malloc() texture[y] in load_tex() failed");
	  y++;
	  }*/
	/*x = 0;
	  while (x < TWIDTH)
	  {
	  y = 0;
	  while (y < THEIGHT)
	  {
	  xycolor = y * 128 / THEIGHT + x * 128 / TWIDTH;
	  r->texture[0][TWIDTH * y + x] = mlx_xpm_file_to_image(r->mlx, "textures/mur.xpm", &w, &h);\
	  65536 * 154 * (x != y && x != TWIDTH - y)*/;
	/*r->texture[1][TWIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor;
	  r->texture[2][TWIDTH * y + x] = 256 * xycolor + 65536 * xycolor;
	  y++;
	  }
	  x++;
	  }*/
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
	//mlx_hook(r.win, 2, 64, key, &r);
	mlx_key_hook(r.win, key, &r);
	mlx_loop(r.mlx);
	return (0);
}
