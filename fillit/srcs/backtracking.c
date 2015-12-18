/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:03:51 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/18 17:54:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_backtracking(t_coord **first)
{
	t_coord *coord;
	t_varf v;
	char **tab;
	int tablen;

	tab = NULL;
	tablen = 3;
	v.x = 0;
	v.y = 0;
	coord = *first;
	tab = ft_empty(tab, tablen);
	coord = *ft_move(&coord, v.x, v.y);
	ft_tab_store(tab, &coord);
}
