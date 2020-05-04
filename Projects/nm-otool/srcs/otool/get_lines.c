/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:00:06 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 16:50:54 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static void	ft_format(char **hex_byte)
{
	size_t	padding_length;
	char	*padding;
	size_t	i;

	padding_length = 2 - ft_strlen(*hex_byte);
	padding = (char *)malloc(sizeof(char) * padding_length + 1);
	i = 0;
	if (padding)
	{
		while (i < padding_length)
		{
			padding[i] = '0';
			i++;
		}
		padding[i] = '\0';
		*hex_byte = ft_strjoin(padding, *hex_byte);
	}
}

static char	*ft_byte_to_hex(uint8_t value, int value_arch)
{
	char	*hex;
	uint8_t	base;
	int		i;
	int		str_end;

	base = 16;
	i = (value_arch == 32) ? (value_len(value, base)) :
		(value_len_64(value, base));
	str_end = i;
	if ((hex = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i--;
	while (value != 0)
	{
		if (value % base > 9)
			hex[i] = (value % base) + 87;
		else
			hex[i] = '0' + value % base;
		value /= base;
		i--;
	}
	hex[str_end] = '\0';
	ft_format(&hex);
	return (hex);
}

char		*get_hex(char *offset, char *sect_end, int reverse, int value_arch)
{
	char	*hex_line;
	int		i;
	int		hex_char;
	char	*hex_byte;

	i = 1;
	hex_char = 0;
	hex_line = (char *)ft_memalloc(48);
	while (i < 17 && offset < sect_end)
	{
		hex_byte = ft_byte_to_hex(*offset, value_arch);
		hex_line[hex_char++] = hex_byte[0];
		hex_line[hex_char++] = hex_byte[1];
		if (reverse)
		{
			if (i && (i % 4 == 0))
				hex_line[hex_char++] = ' ';
		}
		else
			hex_line[hex_char++] = ' ';
		offset++;
		i++;
	}
	hex_line[hex_char] = '\0';
	return (hex_line);
}

char		*ft_value_format(char *value, uint8_t type_flag, int padding_value)
{
	size_t	value_length;
	size_t	padding_length;
	char	*padding;
	char	padding_char;
	size_t	i;

	padding_char = (type_flag & N_TYPE) == N_UNDF ? ' ' : '0';
	value_length = ft_strlen(value);
	padding_length = padding_value - value_length;
	if ((padding = (char *)malloc(sizeof(char) * padding_length + 1)) == NULL)
	{
		ft_putendl_fd("Value formatting failed.", 2);
		return (NULL);
	}
	i = 0;
	while (i < padding_length)
	{
		padding[i] = padding_char;
		i++;
	}
	padding[i] = '\0';
	return (ft_strjoin(padding, value));
}
