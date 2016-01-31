/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:54:01 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 19:21:38 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

int			ft_colors(int **tab, int y, int x)
{
	if (tab[y][x] == 0)
		return (1);
	if (tab[y][x] >= 2 && tab[y][x] <= 4)
		return (5);
	if (tab[y][x] == 8)
		return (6);
	if (tab[y][x] == 16 || tab[y][x] == 32)
		return (7);
	if (tab[y][x] >= 128 && tab[y][x] <= 2048)
		return (8);
	return (9);
}

void		background(t_win *box, int **tab)
{
	wbkgd(box->a, COLOR_PAIR(ft_colors(tab, 0, 0)));
	wbkgd(box->b, COLOR_PAIR(ft_colors(tab, 0, 1)));
	wbkgd(box->c, COLOR_PAIR(ft_colors(tab, 0, 2)));
	wbkgd(box->d, COLOR_PAIR(ft_colors(tab, 0, 3)));
	wbkgd(box->e, COLOR_PAIR(ft_colors(tab, 1, 0)));
	wbkgd(box->f, COLOR_PAIR(ft_colors(tab, 1, 1)));
	wbkgd(box->g, COLOR_PAIR(ft_colors(tab, 1, 2)));
	wbkgd(box->h, COLOR_PAIR(ft_colors(tab, 1, 3)));
	wbkgd(box->i, COLOR_PAIR(ft_colors(tab, 2, 0)));
	wbkgd(box->j, COLOR_PAIR(ft_colors(tab, 2, 1)));
	wbkgd(box->k, COLOR_PAIR(ft_colors(tab, 2, 2)));
	wbkgd(box->l, COLOR_PAIR(ft_colors(tab, 2, 3)));
	wbkgd(box->m, COLOR_PAIR(ft_colors(tab, 3, 0)));
	wbkgd(box->n, COLOR_PAIR(ft_colors(tab, 3, 1)));
	wbkgd(box->o, COLOR_PAIR(ft_colors(tab, 3, 2)));
	wbkgd(box->p, COLOR_PAIR(ft_colors(tab, 3, 3)));
}

void		display(t_win *box, int **tab)
{
	background(box, tab);
	mvwprintw(box->a, X / 2, Y / 2, (tab[0][0]) ? (ft_itoa(tab[0][0])) : (""));
	mvwprintw(box->b, X / 2, Y / 2, (tab[0][1]) ? (ft_itoa(tab[0][1])) : (""));
	mvwprintw(box->c, X / 2, Y / 2, (tab[0][2]) ? (ft_itoa(tab[0][2])) : (""));
	mvwprintw(box->d, X / 2, Y / 2, (tab[0][3]) ? (ft_itoa(tab[0][3])) : (""));
	mvwprintw(box->e, X / 2, Y / 2, (tab[1][0]) ? (ft_itoa(tab[1][0])) : (""));
	mvwprintw(box->f, X / 2, Y / 2, (tab[1][1]) ? (ft_itoa(tab[1][1])) : (""));
	mvwprintw(box->g, X / 2, Y / 2, (tab[1][2]) ? (ft_itoa(tab[1][2])) : (""));
	mvwprintw(box->h, X / 2, Y / 2, (tab[1][3]) ? (ft_itoa(tab[1][3])) : (""));
	mvwprintw(box->i, X / 2, Y / 2, (tab[2][0]) ? (ft_itoa(tab[2][0])) : (""));
	mvwprintw(box->j, X / 2, Y / 2, (tab[2][1]) ? (ft_itoa(tab[2][1])) : (""));
	mvwprintw(box->k, X / 2, Y / 2, (tab[2][2]) ? (ft_itoa(tab[2][2])) : (""));
	mvwprintw(box->l, X / 2, Y / 2, (tab[2][3]) ? (ft_itoa(tab[2][3])) : (""));
	mvwprintw(box->m, X / 2, Y / 2, (tab[3][0]) ? (ft_itoa(tab[3][0])) : (""));
	mvwprintw(box->n, X / 2, Y / 2, (tab[3][1]) ? (ft_itoa(tab[3][1])) : (""));
	mvwprintw(box->o, X / 2, Y / 2, (tab[3][2]) ? (ft_itoa(tab[3][2])) : (""));
	mvwprintw(box->p, X / 2, Y / 2, (tab[3][3]) ? (ft_itoa(tab[3][3])) : (""));
}
