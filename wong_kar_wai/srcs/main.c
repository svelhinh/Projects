/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:27:39 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 15:58:51 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

int			main(void)
{
	int		**tab;
	t_win	box;

	if (check_value(WIN_VALUE))
	{
		tab = init_tab(1);
		initscr();
		curs_set(0);
		raw();
		keypad(stdscr, TRUE);
		tab = game(tab, &box, 0);
		check_wl(tab);
		if (check_win(tab, 0))
			(continue_play()) ? (tab = game(tab, &box, 1)) : (0);
		clear();
		endwin();
	}
	return (0);
}
