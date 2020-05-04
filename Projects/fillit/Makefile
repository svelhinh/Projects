# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 16:51:55 by svelhinh          #+#    #+#              #
#    Updated: 2015/12/28 17:24:26 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = \
	srcs/main.c srcs/errors.c srcs/get_next_line.c srcs/fonctions.c \
	srcs/store_file.c srcs/move.c srcs/backtracking.c srcs/check_store.c

LIB = lib/libft.a

INCLUDES = includes

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "\033[91mIl n'y a plus rien a faire"

$(NAME):
	@make re -C lib
	@echo "\033[93mDebut de la compilation"
	@gcc -o $(NAME) -Wall -Wextra -Werror $(SRC) $(LIB) -I $(INCLUDES)
	@echo "\033[92mCompilation terminee\n\n\033[93mSuppression de la librairie"
	@make fclean -C lib
	@echo "\033[92mSuppression de la librairie terminee\n"

clean:
	@rm -f $(OBJ)
	@echo "\033[96mSuppression des objets termine"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[96mSuppression de l'executable termine\n"

re: fclean all

.PHONY: all clean fclean re
