# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 16:51:55 by svelhinh          #+#    #+#              #
#    Updated: 2015/12/21 13:04:50 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

SRC = srcs/alcu.c srcs/playing.c srcs/matches.c srcs/check_file.c

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
