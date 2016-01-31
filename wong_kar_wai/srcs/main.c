/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:27:39 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 13:15:08 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static void	colors(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
}

static void	borders(t_win *box)
{
	box(box->a, ACS_VLINE, ACS_HLINE);
	box(box->b, ACS_VLINE, ACS_HLINE);
	box(box->c, ACS_VLINE, ACS_HLINE);
	box(box->d, ACS_VLINE, ACS_HLINE);
	box(box->e, ACS_VLINE, ACS_HLINE);
	box(box->f, ACS_VLINE, ACS_HLINE);
	box(box->g, ACS_VLINE, ACS_HLINE);
	box(box->h, ACS_VLINE, ACS_HLINE);
	box(box->i, ACS_VLINE, ACS_HLINE);
	box(box->j, ACS_VLINE, ACS_HLINE);
	box(box->k, ACS_VLINE, ACS_HLINE);
	box(box->l, ACS_VLINE, ACS_HLINE);
	box(box->m, ACS_VLINE, ACS_HLINE);
	box(box->n, ACS_VLINE, ACS_HLINE);
	box(box->o, ACS_VLINE, ACS_HLINE);
	box(box->p, ACS_VLINE, ACS_HLINE);
}

static void	display_boxes(t_win *box)
{
	attron(COLOR_PAIR(1));
	bkgd(COLOR_PAIR(1));
	box->a = subwin(stdscr, X, Y, 0, 0);
	box->b = subwin(stdscr, X, Y, 0, Y);
	box->c = subwin(stdscr, X, Y, 0, Y * 2);
	box->d = subwin(stdscr, X, Y, 0, Y * 3);
	box->e = subwin(stdscr, X, Y, X, 0);
	box->f = subwin(stdscr, X, Y, X, Y);
	box->g = subwin(stdscr, X, Y, X, Y * 2);
	box->h = subwin(stdscr, X, Y, X, Y * 3);
	box->i = subwin(stdscr, X, Y, X * 2, 0);
	box->j = subwin(stdscr, X, Y, X * 2, Y);
	box->k = subwin(stdscr, X, Y, X * 2, Y * 2);
	box->l = subwin(stdscr, X, Y, X * 2, Y * 3);
	box->m = subwin(stdscr, X, Y, X * 3, 0);
	box->n = subwin(stdscr, X, Y, X * 3, Y);
	box->o = subwin(stdscr, X, Y, X * 3, Y * 2);
	box->p = subwin(stdscr, X, Y, X * 3, Y * 3);
	attroff(COLOR_PAIR(1));
	borders(box);
}

int			main(void)
{
	int		**tab;
	t_win	box;
	int		key;

	if (check_value(WIN_VALUE))
	{
		tab = init_tab(1);
		initscr();
		raw();
		keypad(stdscr, TRUE);
		key = 0;
		while (key != 27)
		{
			clear();
			colors();
			display_boxes(&box);
			display(&box, tab);
			refresh();
			key = getch();
			if (key == KEY_DOWN || key == KEY_UP || key == KEY_LEFT
					|| key == KEY_RIGHT)
			{
				if (!check_tab(tab))
				{
					tab = check_keys(tab, key);
					if (check_win(tab))
						break ;
				}
				else
					break ;
			}
		}
		clear();
		endwin();
	}
	return (0);
}
