/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:54:45 by lnieto-m          #+#    #+#             */
/*   Updated: 2018/08/01 18:06:34 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*zone;

	zone = malloc(sizeof(zone) * size);
	if (zone == NULL)
		return (NULL);
	ft_bzero(zone, size);
	return (zone);
}
