/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:38:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/08 14:38:48 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, src, len);
	while (i < len)
	{
		((char *)dst)[i] = tmp[i];
		i++;
	}
	return (dst);
}
