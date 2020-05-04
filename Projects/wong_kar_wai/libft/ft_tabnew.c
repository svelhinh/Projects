/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjarross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:15:29 by tjarross          #+#    #+#             */
/*   Updated: 2016/01/30 14:34:47 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabnew(size_t size)
{
	int *tab;

	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	size--;
	while (size)
		tab[size--] = 0;
	return (tab);
}
