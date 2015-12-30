# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 16:51:55 by svelhinh          #+#    #+#              #
#    Updated: 2015/12/30 11:31:04 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/main.c srcs/line.c

LIB = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

INCLUDES = includes

OBJ = $(SRC:.c=.o)

all: $(NAME)
		@echo "\033[91mIl n'y a plus rien a faire"

$(NAME):
		@echo "\033[96mCompilation en cours"
		@gcc -o $(NAME) -Wall -Wextra -Werror $(SRC) $(LIB) -I $(INCLUDES)
		@echo "\033[92mCompilation terminee\n"

clean:
		@echo "\033[96mSuppression des objets en cours"
		@rm -f $(OBJ)
		@echo "\033[92mSuppression des objets terminee\n"

fclean: clean
		@echo "\033[96mSuppression de l'executable en cours"
		@rm -f $(NAME)
		@echo "\033[92mSuppression de l'executable terminee\n"

re: fclean all

.PHONY: all clean fclean re
