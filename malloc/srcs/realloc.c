/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:54:47 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/11 15:22:55 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_block	*block_is_allocated(t_block *ptr_block_to_find)
{
	t_area	*ptr_area;
	int		ptr_found;
	t_block *ptr_block;

	ptr_area = g_begin;
	ptr_block = ptr_area->block;
	ptr_found = FALSE;
	while (ptr_area && !ptr_found)
	{
		ptr_block = ptr_area->block;
		while (ptr_block &&
			((void *)ptr_block + sizeof(t_block) != ptr_block_to_find))
			ptr_block = ptr_block->next;
		if (ptr_block)
			ptr_found = TRUE;
		ptr_area = ptr_area->next;
	}
	if (!ptr_found)
		return (NULL);
	return (ptr_block);
}

void			*realloc(void *ptr, size_t size)
{
	t_block	*ptr_block;
	void	*new_ptr;

	if (!ptr)
		return (malloc(size));
	if (!size)
	{
		free(ptr);
		return (NULL);
	}
	if (!(ptr_block = block_is_allocated(ptr)))
		return (NULL);
	if (size <= ptr_block->size - sizeof(t_block))
	{
		ptr_block->size = size + sizeof(t_block);
		return (ptr);
	}
	if (!(new_ptr = malloc(size)))
		return (ptr);
	new_ptr = ft_memcpy(new_ptr, ptr, ptr_block->size - sizeof(t_block));
	free(ptr);
	return (new_ptr);
}
