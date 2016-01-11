/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 10:50:06 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/11 18:29:14 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	**store(char **tmp, int nbl, int **nbn)
{
	t_fdf	v;

	if (!(v.map = (float **)malloc(sizeof(float *) * (nbl + 1))))
		ft_exit("le malloc de map dans store() a echoue");
	v.y = 0;
	v.j = 0;
	while (tmp[v.j] && !(v.i = 0))
	{
		v.split = ft_strsplit(tmp[v.j], ' ');
		**nbn = tablen(v.split);
		v.x = 0;
		if (!(v.map[v.y] = (float *)malloc(sizeof(float) * **nbn)))
			ft_exit("le malloc de map[y] dans store() a echoue");
		while (v.split[v.i])
		{
			v.map[v.y][v.x] = ft_atoi(v.split[v.i]);
			v.x++;
			v.i++;
		}
		free(v.split);
		v.y++;
		v.j++;
	}
	v.map[v.y] = NULL;
	return (v.map);
}

float			**read_map(char *file, int *nbl, int *nbn)
{
	t_fdf	v;

	*nbl = 0;
	((v.fd = open(file, O_RDONLY)) == -1) ? (ft_exit("Aucun fichier")) : (0);
	while (get_next_line(v.fd, &v.line) > 0)
	{
		(*nbl)++;
		free(v.line);
	}
	(close(v.fd) == -1) ? (ft_exit("La fermeture 1 du fichier a echoue")) : (0);
	((v.fd = open(file, O_RDONLY)) == -1) ? (ft_exit("Aucun fichier")) : (0);
	if (!(v.tmp = (char **)malloc(sizeof(char *) * *nbl)))
		ft_exit("Le malloc de tmp dans read_map() a echoue");
	*nbl = 0;
	while (get_next_line(v.fd, &v.line) > 0)
	{
		v.tmp[*nbl] = ft_strdup(v.line);
		(*nbl)++;
		free(v.line);
	}
	v.tmp[*nbl] = NULL;
	(close(v.fd) == -1) ? (ft_exit("La fermeture 2 du fichier a echoue")) : (0);
	v.map = store(v.tmp, *nbl, &nbn);
	free(v.tmp);
	return (v.map);
}
