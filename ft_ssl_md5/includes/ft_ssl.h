/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:30:51 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/30 16:29:18 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"

# define LROT(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
# define RROT(x, c) (((x) >> (c)) | ((x) << (32 - (c))))

typedef enum		e_options
{
	OP_NONE = 0,
	OP_PRINT = 1,
	OP_QUIET = 2,
	OP_REVERSE = 4
}					t_options;

typedef enum		e_errors
{
	ER_USAGE,
	ER_INVALID_COMMAND,
	ER_WRONG_FILE,
	ER_READ_FILE,
	ER_READ_STDIN,
	ER_SUM_NO_STRING
}					t_errors;

typedef enum		e_commands
{
	CM_NONE,
	CM_MD5,
	CM_SHA256,
}					t_commands;

typedef struct		s_ssl
{
	char	*file;
	int		stdin;
	char	*msg;
	size_t	msg_len;
	char	*msg_digest;
}					t_ssl;

t_options			g_options;
t_commands			g_command;
t_ssl				*g_ssl;
unsigned int		g_nb_msg;
unsigned int		*g_k;

unsigned char		*md5(unsigned char *initial_msg, unsigned int initial_len);
void				init_md5(unsigned int (*r)[64], unsigned int (*h)[4]);
void				hash_new_msg_md5(unsigned char *new_msg, unsigned int len,
	unsigned int (*h)[4], unsigned int r[64]);

unsigned char		*sha256(unsigned char *msg, unsigned int len);
void				init_sha256(unsigned int (*h1)[8]);
void				hash_new_msg_sha256(unsigned char *new_msg,
	unsigned int len, unsigned int (*h1)[8]);

void				parse_command_line(char **args, int len);

void				print_error(t_errors error, char *command, char *file);

void				print_msg_digest(int msg_i);

char				*get_str_command();
char				*read_file(char *path, size_t *msg_len, int print_errors);
char				*read_stdin(size_t *msg_len);
void				append_msg(char *file, char *msg, size_t msg_len, int stdin);

#endif
