/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:28:25 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 19:34:26 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static void	display_menu(void)
{
	mvprintw(LINES / 8, COLS / 2 - 30,
			"       ::::::::     :::::::::          :::       ::::::::");
	mvprintw(LINES / 8 + 1, COLS / 2 - 30,
			"     :+:    :+:   :+:      :+:       :+:      :+:      :+:");
	mvprintw(LINES / 8 + 2, COLS / 2 - 30,
			"          +:+   +:+        +:+    +:+ +:+    :+:      +:+");
	mvprintw(LINES / 8 + 3, COLS / 2 - 30,
			"       +#+     +#+        +#+   +#+  +:+      +#+#+#+#+");
	mvprintw(LINES / 8 + 4, COLS / 2 - 30,
			"    +#+       +#+        +#+   +#+#+#+#+#+  +#+      +#+");
	mvprintw(LINES / 8 + 5, COLS / 2 - 30,
			"  #+#         #+#      #+#         #+#     #+#      #+#");
	mvprintw(LINES / 8 + 6, COLS / 2 - 30,
			"###########    ########           ###       ########");
}

void		menu(void)
{
	display_menu();
	mvprintw(LINES / 8 + 10, COLS / 2 - 4, "1 : PLAY");
	mvprintw(LINES / 8 + 12, COLS / 2 - 4, "2 : EXIT");
}
