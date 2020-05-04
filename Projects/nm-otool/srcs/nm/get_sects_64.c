/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sects_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 17:39:33 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 14:15:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

char		get_sym_sect_64(t_sym *sym, t_sect **sects)
{
	t_sect *current;

	current = *sects;
	while (current)
	{
		if (current->idx == sym->sect_nb)
			return (available_section(current->name));
		current = current->next;
	}
	return (' ');
}

void		get_sects_64(t_sect **sect, uint32_t *id, t_load_com *lc)
{
	t_seg_com_64	*segment;
	uint32_t		i_sect;
	t_sec_64		*section;

	segment = (t_seg_com_64 *)lc;
	i_sect = 0;
	section = (t_sec_64 *)((void *)segment + sizeof(t_seg_com_64));
	while (i_sect < segment->nsects)
	{
		(*sect)->name = section[i_sect].sectname;
		(*sect)->idx = (*id)++;
		if (((*sect)->next = (t_sect *)ft_memalloc(sizeof(t_sect))) == NULL ||
			i_sect == segment->nsects - 1)
		{
			(*sect)->next = NULL;
			break ;
		}
		*sect = (*sect)->next;
		i_sect++;
	}
}
