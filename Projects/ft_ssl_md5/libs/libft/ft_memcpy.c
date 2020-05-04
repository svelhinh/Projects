/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:02:53 by svelhinh          #+#    #+#             */
/*   Updated: 2017/07/26 14:44:27 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp_src;
	const char	*tmp_dest;

	tmp_src = dest;
	tmp_dest = src;
	while (n--)
	{
		*tmp_src = *tmp_dest;
		tmp_src++;
		tmp_dest++;
	}
	return (dest);
}
