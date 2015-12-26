# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 16:51:55 by svelhinh          #+#    #+#              #
#    Updated: 2015/12/26 15:26:48 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/main.c

LIB = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
		gcc -o $(NAME) -Wall -Wextra -Werror $(SRC) $(LIB)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
