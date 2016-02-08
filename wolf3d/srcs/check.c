/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:35:51 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/08 11:43:01 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_lvl(char *lvl)
{
	int nb;

	if (!ft_strcmp(lvl, "levels/lvl1"))
		nb = 0;
	else if (!ft_strcmp(lvl, "levels/lvl2"))
		nb = 1;
	else if (!ft_strcmp(lvl, "levels/lvl3"))
		nb = 2;
	else
		nb = -1;
	return (nb);
}
