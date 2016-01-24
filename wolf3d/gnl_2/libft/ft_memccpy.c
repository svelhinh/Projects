/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:12:50 by vtata             #+#    #+#             */
/*   Updated: 2015/11/30 19:11:52 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_src;
	unsigned char	*p_dst;

	i = 0;
	p_src = (unsigned char*)src;
	p_dst = (unsigned char*)dst;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		if (p_src[i] == (unsigned char)c)
			return (&p_dst[i + 1]);
		i++;
	}
	p_dst = NULL;
	return (p_dst);
}
