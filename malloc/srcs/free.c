/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:48:19 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/19 12:33:55 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_area	*free_block_if_is_allocated(t_block *block_to_free)
{
	t_area	*area;
	t_area	*last_area;
	t_block *block;
	int		block_found;

	area = g_begin;
	block = NULL;
	block_found = FALSE;
	last_area = area;
	while (area)
	{
		block = area->block;
		while (block && ((void *)block + sizeof(t_block) != block_to_free))
			block = block->next;
		if (block && (block_found = TRUE))
			break ;
		last_area = area;
		area = area->next;
	}
	if (block_found && !block->free)
	{
		block->free = TRUE;
		return (last_area);
	}
	return (NULL);
}

void			free(void *ptr)
{
	t_area	*last_area;
	t_area	*area;
	t_block *block_to_free;

	block_to_free = (t_block *)ptr;
	last_area = NULL;
	area = NULL;
	if (ptr)
	{
		last_area = free_block_if_is_allocated(block_to_free);
		if (last_area && last_area->next && last_area->next->type == LARGE)
		{
			area = last_area->next;
			last_area->next = area->next;
			munmap(area, area->size);
		}
	}
}
