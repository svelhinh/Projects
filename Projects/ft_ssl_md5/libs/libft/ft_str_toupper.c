/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:13:08 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 16:15:04 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(char *s)
{
	size_t	i;
	char	*s2;

	s2 = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_test_malloc(s2);
	i = 0;
	while (s[i])
	{
		s2[i] = ft_toupper(s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
