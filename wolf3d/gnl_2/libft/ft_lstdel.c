/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:43:03 by vtata             #+#    #+#             */
/*   Updated: 2015/12/07 11:52:21 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*to_free;

	tmp = *alst;
	if (tmp)
	{
		while (tmp)
		{
			del(tmp->content, tmp->content_size);
			to_free = tmp;
			tmp = tmp->next;
			free(to_free);
		}
		*alst = NULL;
	}
}
