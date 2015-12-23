# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 16:51:55 by svelhinh          #+#    #+#              #
#    Updated: 2015/12/23 17:23:00 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = \
		srcs/main.c srcs/errors.c srcs/get_next_line.c srcs/fonctions.c \
		srcs/store_file.c srcs/move.c srcs/backtracking.c srcs/check_store.c

LIB = lib/libft.a

INCLUDES = includes

all: $(NAME)

$(NAME):
		gcc -o $(NAME) -Wall -Wextra -Werror $(SRC) $(LIB) -I $(INCLUDES)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
