/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 10:50:06 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/03 12:56:16 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		**store(char **tmp, int nbl, int **nbn)
{
	t_fdf	v;
	int		**map;

	if (!(map = (int **)malloc(sizeof(int *) * (nbl + 1))))
		ft_exit("le malloc de map dans store() a echoue");
	v.y = 0;
	v.j = 0;
	while (tmp[v.j])
	{
		v.split = ft_strsplit(tmp[v.j], ' ');
		**nbn = tablen(v.split);
		v.x = 0;
		v.i = 0;
		if (!(map[v.y] = (int *)malloc(sizeof(int) * **nbn)))
			ft_exit("le malloc de map[y] dans store() a echoue");
		while (v.split[v.i])
		{
			map[v.y][v.x] = ft_atoi(v.split[v.i]);
			//ft_putnbr(map[v.y][v.x]);
			//ft_putchar(' ');
			v.x++;
			v.i++;
		}
		(v.split) ? (free(v.split)) : (ft_exit("Une variable a ete mal free"));
		//ft_putchar('\n');
		//printf("\n");
		v.y++;
		v.j++;
	}
	map[v.y] = NULL;
	return (map);
}

int				**read_map(char *file, int *nbl, int *nbn)
{
	t_fdf	v;
	int		**map;

	v.line = ft_strnew(BUFF_SIZE);
	*nbl = 0;
	((v.fd = open(file, O_RDONLY)) == -1) ? (ft_exit("Aucun fichier")) : (0);
	while (get_next_line(v.fd, &v.line))
		(*nbl)++;
	(close(v.fd) == -1) ? (ft_exit("La fermeture 1 du fichier a echoue")) : (0);
	((v.fd = open(file, O_RDONLY)) == -1) ? (ft_exit("Aucun fichier")) : (0);
	if (!(v.tmp = (char **)malloc(sizeof(char *) * *nbl)))
		ft_exit("Le malloc de tmp dans read_map() a echoue");
	*nbl = 0;
	while (get_next_line(v.fd, &v.line))
	{
		v.tmp[*nbl] = ft_strdup(v.line);
		//printf("%s\n", v.tmp[*nbl]);
		(*nbl)++;
	}
	v.tmp[*nbl] = NULL;
	(close(v.fd) == -1) ? (ft_exit("La fermeture 2 du fichier a echoue")) : (0);
	map = store(v.tmp, *nbl, &nbn);
	return (map);
}
