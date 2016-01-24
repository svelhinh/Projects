/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 08:45:58 by vtata             #+#    #+#             */
/*   Updated: 2015/12/07 12:49:11 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list*)malloc(sizeof(*new_list));
	if (new_list)
	{
		if (content == NULL)
		{
			new_list->content = NULL;
			new_list->content_size = 0;
		}
		else
		{
			new_list->content = malloc(content_size);
			ft_memcpy(new_list->content, content, content_size);
			new_list->content_size = content_size;
		}
		new_list->next = NULL;
	}
	return (new_list);
}
