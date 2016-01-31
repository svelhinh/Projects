/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong_kar_wai.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:33:21 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/31 17:24:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_KAR_WAI_H
# define WONG_KAR_WAI_H
# include <ncurses.h>
# include <time.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# define X LINES / 4
# define Y COLS / 4

typedef struct	s_win
{
	WINDOW		*a;
	WINDOW		*b;
	WINDOW		*c;
	WINDOW		*d;
	WINDOW		*e;
	WINDOW		*f;
	WINDOW		*g;
	WINDOW		*h;
	WINDOW		*i;
	WINDOW		*j;
	WINDOW		*k;
	WINDOW		*l;
	WINDOW		*m;
	WINDOW		*n;
	WINDOW		*o;
	WINDOW		*p;
}				t_win;
enum			e_const
{
	WIN_VALUE = 16
};
int				**init_tab(int j);
void			display(t_win *box, int **tab);
int				**check_keys(int **tab, int key);
int				**ft_move(int **tab, int key, int *ret);
int				**ft_rand(int **tab);
void			ft_random(int *x, int *y, int *nb);
int				check_rand(int **tab);
int				check_tab(int **tab);
int				check_win(int **tab, int i);
int				check_value(int value);
int				**check_keys2(int **tab, int key);
int				**ft_move2(int **tab, int key, int *ret);
int				check_wl(int **tab);
int				**game(int **tab, t_win *box, int i);
int				continue_play(void);
#endif
