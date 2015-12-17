/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:56:17 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/17 17:40:56 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_init(int *nblines, int *error, int *gnlret, int *blk)
{
	*nblines = 0;
	*error = 0;
	*gnlret = 1;
	*blk = 0;
}

char		*ft_letters(char *file)
{
	int		cnt;
	char	c;
	int		i;

	c = 'A';
	i = 0;
	cnt = 0;
	while (file[i])
	{
		if (file[i] == '#')
		{
			file[i] = c;
			cnt++;
		}
		if (cnt == 4)
		{
			cnt = 0;
			c++;
		}
		i++;
	}
	return (file);
}
