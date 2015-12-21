/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 10:22:35 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/21 13:30:02 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 100

typedef struct	s_alcu
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int			winner;
	int			fd;
	char		**m;
	int			nbm;
	int			turn;
	int			i;
	int			nbmr;
}				t_alcu;
int				ft_game(char **m);
char			**ft_player(char **m, int nbm, int *turn);
char			**ft_ia(char **m, int nbm, int *turn);
char			**ft_remove(char **m, int nbmr);
int				ft_nbmatches(char **m);
void			ft_display_matches(char **m);
char			**ft_read_file(int fd);
#endif
