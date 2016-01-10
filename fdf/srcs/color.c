/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:47:56 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/10 18:04:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:49:48 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/10 15:47:22 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*cpy_line(int *tab)
{
	int	*line;
	int	i;

	i = 0;
	if (!(line = (int *)malloc(sizeof(int) * 4)))
		ft_exit("Le malloc de line dans define_color() a echoue");
	while (i < 4)
	{
		line[i] = tab[i];
		i++;
	}
	return (line);
}

int		**init_tab(int **tab)
{
	tab[0][0] = RED1;
	tab[0][1] = RED2;
	tab[0][2] = RED3;
	tab[0][3] = RED4;
	tab[1][0] = PINK1;
	tab[1][1] = PINK2;
	tab[1][2] = PINK3;
	tab[1][3] = PINK4;
	tab[2][0] = BLUE1;
	tab[2][1] = BLUE2;
	tab[2][2] = BLUE3;
	tab[2][3] = BLUE4;
	tab[3][0] = CYAN1;
	tab[3][1] = CYAN2;
	tab[3][2] = CYAN3;
	tab[3][3] = CYAN4;
	return (tab);
}

int		**init_tab2(int **tab)
{
	tab = init_tab(tab);
	tab[4][0] = GREEN1;
	tab[4][1] = GREEN2;
	tab[4][2] = GREEN3;
	tab[4][3] = GREEN4;
	tab[5][0] = YELLOW1;
	tab[5][1] = YELLOW2;
	tab[5][2] = YELLOW3;
	tab[5][3] = YELLOW4;
	tab[6][0] = WHITE1;
	tab[6][1] = WHITE2;
	tab[6][2] = WHITE3;
	tab[6][3] = WHITE4;
	return (tab);
}

int		*define_color(char *color)
{
	int	**tab;
	int	j;
	int	t;
	int	*line;

	t = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * 7)))
		ft_exit("Le malloc de tab dans define_color() a echoue");
	while (t < 7)
	{
		if (!(tab[t] = (int *)malloc(sizeof(int) * 4)))
			ft_exit("Le malloc de tab[t] dans define_color() a echoue");
		t++;
	}
	tab = init_tab2(tab);
	j = WHITE;
	(!ft_strcmp(color, "red")) ? (j = RED) : (0);
	(!ft_strcmp(color, "pink")) ? (j = PINK) : (0);
	(!ft_strcmp(color, "blue")) ? (j = BLUE) : (0);
	(!ft_strcmp(color, "cyan")) ? (j = CYAN) : (0);
	(!ft_strcmp(color, "green")) ? (j = GREEN) : (0);
	(!ft_strcmp(color, "yellow")) ? (j = YELLOW) : (0);
	(!ft_strcmp(color, "white")) ? (j = WHITE) : (0);
	line = cpy_line(tab[j]);
	return (line);
}

int		color(int i2, int j2, t_xy c, t_fdf v)
{
	int	i;
	int	**tab;
	int	j;

	i = 0;
	j = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * 4)))
		ft_exit("Le malloc de tab dans color() a echoue");
	while (j < 4)
	{
		if (!(tab[j] = (int *)malloc(sizeof(int) * 4)))
			ft_exit("Le malloc de tab[j] dans color() a echoue");
		j++;
	}
	tab[0] = define_color(v.av[2]);
	tab[1] = define_color(v.av[3]);
	tab[2] = define_color(v.av[4]);
	tab[3] = define_color(v.av[5]);
	if ((v.map[c.j][c.i] >= c.min && v.map[c.j][c.i] <= c.max / 4)
			|| (v.map[c.j + j2][c.i + i2] >= c.min
			&& v.map[c.j + j2][c.i + i2] <= c.max / 4))
		c.color = tab[0][0];
	if ((v.map[c.j][c.i] > c.max / 4 && v.map[c.j][c.i] <= c.max / 2)
			|| (v.map[c.j + j2][c.i + i2] > c.max / 4
			&& v.map[c.j + j2][c.i + i2] <= c.max / 2))
		c.color = tab[1][1];
	if ((v.map[c.j][c.i] > c.max / 2 && v.map[c.j][c.i] <= 3 * c.max / 4)
			|| (v.map[c.j + j2][c.i + i2] > c.max / 2
			&& v.map[c.j + j2][c.i + i2] <= 3 * c.max / 4))
		c.color = tab[2][2];
	if ((v.map[c.j][c.i] > 3 * c.max / 4 && v.map[c.j][c.i] <= c.max)
			|| (v.map[c.j + j2][c.i + i2] > 3 * c.max / 4
			&& v.map[c.j + j2][c.i + i2] <= c.max))
		c.color = tab[3][3];
	return (c.color);
}
