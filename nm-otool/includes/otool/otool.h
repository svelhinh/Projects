/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:11:04 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 16:52:09 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# include "utils.h"

typedef struct		s_line
{
	char			*addr;
	char			*hex;
	struct s_line	*next;
}					t_line;

char				*ft_value_format(char *value, uint8_t type_flag,
	int padding);
char				*get_hex(char *offset, char *sect_end, int reverse,
	int value_arch);

void				handle_64_otool(char *ptr);
t_sec_64			*get_text_sect_64(t_load_com *lc, int i, int ncmds);
t_line				*get_lines_64(t_sec_64 *text_sect, char *file_ptr);

void				handle_32_otool(char *ptr);
t_sec				*get_text_sect(t_load_com *lc, int i, int ncmds);
t_line				*get_lines(t_sec *text_sect, char *file_ptr);

void				handle_fat_otool(char *ptr);

#endif
