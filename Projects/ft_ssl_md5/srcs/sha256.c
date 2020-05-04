/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:34:20 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 18:50:54 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static unsigned char	*set_new_msg(unsigned char *msg, unsigned int *len)
{
	unsigned int	initial_len;
	long long		bits_len;
	unsigned char	*new_msg;
	unsigned int	i;

	initial_len = *len;
	(*len)++;
	i = 0;
	while ((initial_len * 8 + 1 + i + 64) % 512 != 0)
		i++;
	*len += i / 8;
	new_msg = ft_memalloc(*len + 8);
	ft_memcpy(new_msg, msg, initial_len);
	new_msg[initial_len] = 0b10000000;
	bits_len = 8 * initial_len;
	// If bits_len is little endian, convert to big-endian
	if (ft_is_little_endian())
		bits_len = ft_swap_64_endian(bits_len);
	ft_memcpy(new_msg + *len, &bits_len, 8);
	return (new_msg);
}

unsigned char			*sha256(unsigned char *msg, unsigned int len)
{
	unsigned int	h1[8];
	unsigned char	*h2[8];
	unsigned int	i;
	unsigned char	*new_msg;

	init_sha256(&h1);
	new_msg = set_new_msg(msg, &len);
	hash_new_msg_sha256(new_msg, len, &h1);
	i = -1;
	while (++i < 8)
	{
		h2[i] = ft_memalloc(8);
		ft_test_malloc(h2[i]);
		ft_uint_to_hex_str(h1[i], h2[i]);
	}
	return (
		(unsigned char *)ft_strjoin(ft_strjoin(ft_strjoin(ft_strjoin(
		ft_strjoin(ft_strjoin(ft_strjoin((const char *)h2[0],
		(const char *)h2[1]), (const char *)h2[2]), (const char *)h2[3]),
		(const char *)h2[4]), (const char *)h2[5]), (const char *)h2[6]),
		(const char *)h2[7]));
}
