/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 09:54:48 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/23 13:47:42 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord		*ft_coord(char *file, int tmp, char c)
{
	t_coord	*t;
	t_varf	v;

	v.blk = 0;
	v.x = 0;
	v.y = 0;
	t = (t_coord *)malloc(sizeof(t_coord));
	t->c = c;
	while (v.blk != 4 || tmp == 0)
	{
		if (ft_isalpha(file[tmp]))
		{
			t->x[v.blk] = v.x;
			t->y[v.blk] = v.y;
			v.blk++;
		}
		v.x++;
		tmp++;
		if (tmp % 4 == 0)
		{
			v.x = 0;
			v.y++;
		}
	}
	return (t);
}

t_coord		**ft_store(char *file)
{
	char	c;
	t_coord	*t;
	t_coord	**first;
	size_t	tmp;

	tmp = 0;
	c = 'A';
	first = (t_coord **)malloc(sizeof(t_coord));
	t = ft_coord(file, tmp, c);
	*first = t;
	while (tmp < ft_strlen(file))
	{
		c++;
		tmp = tmp + 16;
		if (tmp < ft_strlen(file))
		{
			t->next = ft_coord(file, tmp, c);
			t = t->next;
		}
	}
	t->next = NULL;
	return (first);
}
