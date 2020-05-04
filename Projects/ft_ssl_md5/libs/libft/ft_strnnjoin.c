/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnnjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:00:19 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/30 17:00:19 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnnjoin(char *s1, char *s2, size_t ns1, size_t ns2)
{
	char		*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (ns1 + ns2))))
		return (NULL);
	while (j < ns1)
		str[i++] = s1[j++];
	j = 0;
	while (j < ns2)
		str[i++] = s2[j++];
	return (str);
}