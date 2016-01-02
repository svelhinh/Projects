/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 14:57:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/02 16:40:13 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y)
{
	printf("x = %d\ny = %d\nbutton = %d\n\n", x, y, button);
	return (0);
}

/*void	linesg(t_env e, int nbl, int nbc, float zoom)
{
	t_xy	c;
	float	l;
	float	h;
	int		i;
	int		j;
	float	sxmin;
	float	symin;

	c.color = 16777215;
	c.xmin = 1000;
	l = 50 * zoom;
	c.ymin = 200;
	h = l / 2;
	j = 1;
	sxmin = c.xmin;
	symin = c.ymin;
	while (j <= nbl - (nbl - nbc))
	{
		i = 1;
		while (i < nbl)
		{
			c.xmax = c.xmin - l;
			c.ymax = c.ymin + h;
			yo(c, e.mlx, e.win);
			c.xmin = c.xmax;
			c.ymin = c.ymax;
			i++;
		}
		c.xmin = sxmin + l;
		c.ymin = symin + h;
		sxmin = c.xmin;
		symin = c.ymin;
		j++;
	}
}

void	linesd(t_env e, int nbl, int nbc, float zoom)
{
	t_xy	c;
	float	l;
	float	h;
	int		i;
	int		j;
	float	sxmin;
	float	symin;

	c.color = 16777215;
	c.xmin = 1000;
	l = 50 * zoom;
	c.ymin = 200;
	h = l / 2;
	j = 1;
	sxmin = c.xmin;
	symin = c.ymin;
	while (j <= nbc + (nbl - nbc))
	{
		i = 1;
		while (i < nbc)
		{
			c.xmax = c.xmin + l;
			c.ymax = c.ymin + h;
			yo(c, e.mlx, e.win);
			c.xmin = c.xmax;
			c.ymin = c.ymax;
			i++;
		}
		c.xmin = sxmin - l;
		c.ymin = symin + h;
		sxmin = c.xmin;
		symin = c.ymin;
		j++;
	}
}*/

char	**read_map(char *file, int *nbl)
{
	char	*line;
	char	**map;
	int		fd;

	line = ft_strnew(BUFF_SIZE);
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("L'ouverture du fichier a echoue");
		exit(0);
	}
	while (get_next_line(fd, &line))
		(*nbl)++;
	if (close(fd) == -1)
	{
		perror("La fermeture du fichier a echoue");
		exit(0);
	}
	fd = open(file, O_RDONLY);
	if (!(map = (char **)malloc(sizeof(char *) * *nbl)))
	{
		perror("malloc failed");
		exit(0);
	}
	*nbl = 0;
	while (get_next_line(fd, &line))
	{
		map[*nbl] = ft_strdup(line);
		printf("%s\n", map[*nbl]);
		(*nbl)++;
	}
	if (close(fd) == -1)
	{
		perror("close failed\n");
		exit(0);
	}
	return (map);
}

int		main(int ac, char **av)
{
	t_env	e;
	float zoom;
	char **map;
	int nbl;
	int nbc;
	(void)ac;

	nbl = 0;
	map = read_map(av[1], &nbl);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2000, 2000, "42");
	nbc = (ft_strlen(map[0]) + 1) / 2;
	zoom = 1;
	//linesd(e, nbl, nbc, zoom);
	//linesg(e, nbl, nbc, zoom);
	//appel_yo(e, nblinesg, nblinesd, sens);
	// DEBUG
	/*c.xmin = 500;
	  c.xmax = 100;
	  c.ymin = 500;
	  c.ymax = 100;
	  yo(c, e.mlx, e.win);
	  c.xmin = 500;
	  c.xmax = 500;
	  c.ymin = 500;
	  c.ymax = 100;
	  yo(c, e.mlx, e.win);
	  c.xmin = 500;
	  c.xmax = 900;
	  c.ymin = 500;
	  c.ymax = 100;
	  yo(c, e.mlx, e.win);
	  c.xmin = 500;
	  c.xmax = 900;
	  c.ymin = 500;
	  c.ymax = 500;
	  yo(c, e.mlx, e.win);
	  c.xmin = 500;
	  c.xmax = 900;
	  c.ymin = 500;
	  c.ymax = 900;
	  yo(c, e.mlx, e.win);
	  c.xmin = 500;
	  c.xmax = 500;
	  c.ymin = 500;
	  c.ymax = 900;
	  yo(c, e.mlx, e.win);
	  c.xmin = 500;
	  c.xmax = 100;
	  c.ymin = 500;
	  c.ymax = 900;
	  yo(c, e.mlx, e.win);
	  c.xmin = 500;
	  c.xmax = 100;
	  c.ymin = 500;
	  c.ymax = 500;*/
	// FIN DU DEBUG
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
