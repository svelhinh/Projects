/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:30:45 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 18:29:58 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int ac, char **av)
{
	g_options = OP_NONE;
	g_command = CM_NONE;
	g_nb_msg = 0;
	parse_command_line(av, ac);
	return (0);
}
