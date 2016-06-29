/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:27:39 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 19:52:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static void	empty_tab(int **tab)
{
	int y;

	y = 0;
	while (y < 4)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
	tab = NULL;
}

void		main2(int key, int **tab)
{
	t_win	box;

	(tab) ? (empty_tab(tab)) : (0);
	tab = init_tab(1);
	clear();
	while (key != 49 && key != 50)
	{
		clear();
		menu();
		key = getch();
	}
	if (key == 50)
	{
		clear();
		endwin();
		return ;
	}
	tab = game(tab, &box, 0);
	check_wl(tab);
	if (check_win(tab, 0))
		(continue_play(tab)) ? (tab = game(tab, &box, 1)) : (0);
}

int			main(void)
{
	int		**tab;
	int		key;

	if (check_value(WIN_VALUE))
	{
		tab = NULL;
		initscr();
		curs_set(0);
		raw();
		keypad(stdscr, TRUE);
		key = 0;
		main2(key, tab);
		clear();
		endwin();
	}
	else
		ft_putstr("\033[91mWrong WIN_VALUE\n");
	return (0);
}
