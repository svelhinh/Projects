/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:04:15 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 19:22:42 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static void	colors(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_BLACK, COLOR_CYAN);
	init_pair(7, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(8, COLOR_BLACK, COLOR_YELLOW);
	init_pair(9, COLOR_BLACK, COLOR_RED);
}

static void	display_boxes(t_win *box)
{
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
}

int			**game(int **tab, t_win *box, int i)
{
	int key;

	key = 0;
	while (key != 27 && !check_win(tab, i))
	{
		clear();
		colors();
		display_boxes(box);
		display(box, tab);
		refresh();
		key = getch();
		if (key == KEY_DOWN || key == KEY_UP || key == KEY_LEFT
				|| key == KEY_RIGHT)
		{
			if (!check_tab(tab))
				tab = check_keys(tab, key);
			else
				break ;
		}
	}
	(key == 27) ? (main2(key, tab)) : (0);
	return (tab);
}

int			continue_play(int **tab)
{
	int key;

	attron(COLOR_PAIR(2));
	mvprintw(X * 2 + 2, Y * 2 - 8, "PRESS ENTER TO CONTINUE");
	mvprintw(X * 2 + 3, Y * 2 - 10, "PRESS ESC TO GO BACK TO MENU");
	attroff(COLOR_PAIR(2));
	key = 0;
	while (key != 10 && key != 27)
		key = getch();
	if (key == 10)
		return (1);
	else if (key == 27)
		main2(key, tab);
	return (0);
}
