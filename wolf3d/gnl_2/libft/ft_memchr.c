/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:18:38 by vtata             #+#    #+#             */
/*   Updated: 2015/12/03 08:55:54 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c2;
	void			*p;
	size_t			i;

	c2 = (unsigned char)c;
	str = (unsigned char*)s;
	p = NULL;
	i = 0;
	while (i < n)
	{
		if (str[i] == c2)
		{
			p = (str + i);
			return (p);
		}
		i++;
	}
	return (p);
}
