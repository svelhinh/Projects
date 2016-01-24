/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:23:50 by vtata             #+#    #+#             */
/*   Updated: 2015/12/02 22:39:10 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	while (s[i] != c && i > 0)
		i--;
	if (i == 0 && s[i] != c)
		return (NULL);
	str = (char*)&s[i];
	return (str);
}
