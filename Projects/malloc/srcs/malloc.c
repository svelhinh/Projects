/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:57:16 by svelhinh          #+#    #+#             */
/*   Updated: 2017/05/11 14:42:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			get_area_type(size_t size)
{
	if (size > SMALL)
		return (SMALL + 1);
	else if (size > TINY)
		return (SMALL);
	return (TINY);
}

static void	*malloc_small_tiny(size_t size)
{
	t_area	*ptr_area;
	t_block	*ptr_block;
	t_block	*ptr_new_block;
	int		area_type;

	area_type = get_area_type(size);
	if (!(ptr_area = find_area(area_type, size)))
		return (create_new_area(size));
	ptr_block = find_block(ptr_area, size);
	if (!ptr_block->free && !ptr_block->next)
	{
		ptr_new_block = (void *)ptr_block + ptr_block->size;
		ptr_new_block->next = NULL;
		ptr_block->next = ptr_new_block;
	}
	else
		ptr_new_block = ptr_block;
	ptr_new_block->size = size + sizeof(t_block);
	ptr_new_block->free = FALSE;
	ptr_area->size += ptr_new_block->size;
	return (((void *)ptr_new_block) + sizeof(t_block));
}

/*
**	Si g_begin vaut NULL, ca veut dire qu'on n'a encore rien malloc,
**	alors on cree la premiere zone.
**	Sinon, on ajoute une zone en fonction de la taille demandee
*/

void		*malloc(size_t size)
{
	if (!size)
		return (NULL);
	if (!g_begin)
		return (create_first_area(size));
	else
	{
		if (size > SMALL)
			return (create_new_area(size));
		else
			return (malloc_small_tiny(size));
	}
	return (NULL);
}
