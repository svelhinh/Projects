/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:54:01 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/30 16:48:50 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

void		display(t_win *box, int **tab)
{
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
