# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 16:51:55 by svelhinh          #+#    #+#              #
#    Updated: 2016/01/25 11:56:02 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = srcs/main.c srcs/mlx.c srcs/line.c srcs/functions.c srcs/parser.c \
	  gnl/get_next_line.c srcs/raycasting.c

LIB = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

INCLUDES = includes

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "\033[91mIl n'y a plus rien a faire"

$(NAME):
		@make re -C libft
		@echo "\033[96mCompilation"
		@gcc -o $(NAME) -Wall -Wextra -Werror $(SRC) $(LIB) $(LIBFT) -I $(INCLUDES)
		@make fclean -C libft

clean:
		@echo "\033[96mSuppression des objets"
		@rm -f $(OBJ)

fclean: clean
		@echo "\033[96mSuppression de l'executable"
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
