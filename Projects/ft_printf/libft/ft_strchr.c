/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:40:02 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/08 14:40:02 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s2;
	size_t	i;

	s2 = NULL;
	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
	{
		s2 = (char *)&s[i];
		return (s2);
	}
	return (NULL);
}
