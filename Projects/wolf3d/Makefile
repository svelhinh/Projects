# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 16:51:55 by svelhinh          #+#    #+#              #
#    Updated: 2017/03/23 15:22:07 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = srcs/main.c srcs/events.c srcs/draw.c srcs/functions.c srcs/parser.c \
	  gnl/get_next_line.c srcs/raycasting.c srcs/load_tex.c srcs/movement.c \
	  srcs/check.c srcs/menu.c srcs/play.c srcs/options.c srcs/rules.c \
	  srcs/resolution.c srcs/pause.c srcs/events2.c srcs/colors.c

LIB = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

INCLUDES = includes

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

SHELL = ZSH

all: $(NAME)
	@echo "\033[91mFin"

$(NAME): $(OBJ)
		@echo "\n\033[91mFin de la compilation du wolf3d\n\033[92mCompilation de la libft"
		@make -C libft
		@gcc -o $(NAME) $(OBJ) $(LIB) $(LIBFT) -g -Wall -Wextra -Werror

%.o: %.c
		@echo -n "\033[92m."
		@gcc -o $@ -c $< -Wall -Wextra -Werror -I $(INCLUDES)

clean:
		@make clean -C libft
		@echo "\033[96mSuppression des objets du wolf3d"
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C libft
		@echo "\033[96mSuppression de l'executable wolf3d"
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
