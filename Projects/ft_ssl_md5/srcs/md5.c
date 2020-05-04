/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:32:56 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 18:50:51 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static unsigned char	*set_new_msg(unsigned char *msg, unsigned int *len)
{
	unsigned int	bits_len;
	unsigned int	initial_len;
	unsigned char	*new_msg;

	initial_len = *len;
	*len = *len * 8 + 1;	// Permet d'avoir la longueur en bits du message + 1 pour ajouter le bit "1" au message
	while (*len % 512 != 448)	// Permet d'avoir la longueur en bits pour ajouter les bits "0" de padding
		(*len)++;
	*len /= 8;	// On divise par 8 pour avoir la longueur réelle du nouveau message
	new_msg = ft_memalloc(*len + 64);	// On crée le nouveau message avec la nouvelle taille + 64 bits pour ajouter plus tard la taille du message initial codée en 64-bit little-endian
	ft_memcpy(new_msg, msg, initial_len);	// On copie le message initial dans le nouveau
	new_msg[initial_len] = 0b10000000;	// On met le bit "1" à la suite du message initial dans le nouveau message. On laisse tous les autres bits à "0"
	bits_len = 8 * initial_len;
	ft_memcpy(new_msg + *len, &bits_len, 4);	// On ajoute donc ici la taille du message initial codée en 64-bit little-endian
	return (new_msg);
}

unsigned char			*md5(unsigned char *msg, unsigned int len)
{
	unsigned int	r[64];
	unsigned int	i;
	unsigned int	h[4];
	unsigned char	*new_msg;
	unsigned char	*h2[4];

	init_md5(&r, &h);
	new_msg = set_new_msg(msg, &len);
	hash_new_msg_md5(new_msg, len, &h, r);
	i = 0;
	while (i < 4)
	{
		h[i] = ft_swap_32_endian(h[i]);
		h2[i] = ft_memalloc(8);
		ft_uint_to_hex_str(h[i], h2[i]);
		i++;
	}
	return (
		(unsigned char *)ft_strjoin(ft_strjoin(ft_strjoin((const char *)h2[0],
		(const char *)h2[1]), (const char *)h2[2]), (const char *)h2[3]));
}
