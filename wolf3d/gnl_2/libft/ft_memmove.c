/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:43:19 by vtata             #+#    #+#             */
/*   Updated: 2015/11/30 19:13:33 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;
	char	*tmp;

	i = 0;
	s = (char*)src;
	d = (char*)dst;
	tmp = ft_strdup(s);
	while (i < len)
	{
		d[i] = tmp[i];
		i++;
	}
	return (dst);
}
