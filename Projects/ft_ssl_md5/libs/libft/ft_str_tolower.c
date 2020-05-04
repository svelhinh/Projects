/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:57:12 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 16:16:08 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_tolower(char *s)
{
	size_t	i;
	char	*s2;

	s2 = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_test_malloc(s2);
	i = 0;
	while (s[i])
	{
		s2[i] = ft_tolower(s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
