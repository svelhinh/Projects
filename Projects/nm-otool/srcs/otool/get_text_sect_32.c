/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text_sect_32.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:00:06 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 16:40:30 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static t_seg_com	*get_text_seg(t_load_com *lc, int i, int ncmds)
{
	t_seg_com *lc_seg;

	while (i < ncmds)
	{
		lc_seg = (t_seg_com	*)lc;
		if (!ft_strcmp(lc_seg->segname, SEG_TEXT) ||
			!ft_strcmp(lc_seg->segname, ""))
			break ;
		i++;
		lc = (void *)lc + lc->cmdsize;
	}
	return (lc_seg);
}

t_sec				*get_text_sect(t_load_com *lc, int i, int ncmds)
{
	t_seg_com	*lc_seg;
	int			nsects;
	size_t		seg_struct_len;
	t_sec		*section;

	lc_seg = get_text_seg(lc, i, ncmds);
	i = 0;
	nsects = lc_seg->nsects;
	seg_struct_len = sizeof(t_seg_com);
	section = (t_sec *)((void *)lc_seg + seg_struct_len);
	while (i < nsects)
	{
		if (!ft_strcmp(section[i].sectname, SECT_TEXT))
			return (&section[i]);
		i++;
	}
	return (NULL);
}
