/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64_otool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:00:06 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 16:35:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static void			print_lines(t_line *lines)
{
	while (lines)
	{
		ft_putstr(lines->addr);
		ft_putchar('\t');
		ft_putendl(lines->hex);
		lines = lines->next;
	}
}

void				handle_64_otool(char *ptr)
{
	uint8_t				i;
	t_mach_header_64	*header;
	t_load_com			*lc;
	t_sec_64			*txt_sect;
	t_line				**lines;

	lc = (void *)ptr + sizeof(*header);
	header = (t_mach_header_64 *)ptr;
	lines = (t_line **)ft_memalloc(sizeof(t_line *));
	i = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			txt_sect = get_text_sect_64(lc, i, header->ncmds);
			if (txt_sect && (*lines = get_lines_64(txt_sect, ptr)))
				if (lines)
					print_lines(*lines);
			break ;
		}
		i++;
		lc = (void *)lc + lc->cmdsize;
	}
}
