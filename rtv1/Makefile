# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 16:51:55 by svelhinh          #+#    #+#              #
#    Updated: 2016/02/18 18:14:43 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC2 = main.c events.c geometry.c parser.c

SRC = $(addprefix srcs/, $(SRC2))

LIB = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

INCLUDES = includes

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

SHELL = ZSH

all: $(NAME)
	@echo "\033[91mFin"

$(NAME): $(OBJ)
		@echo "\n\033[91mFin de la compilation du rtv1\n\033[92mCompilation de la libft"
		@make -C libft
		@gcc -o $(NAME) $(OBJ) $(LIB) $(LIBFT) -Wall -Wextra -Werror

%.o: %.c
		@echo -n "\033[92m."
		@gcc -o $@ -c $< -Wall -Wextra -Werror -I $(INCLUDES)

clean:
		@echo "\033[96mSuppression des objets du rtv1"
		@rm -f $(OBJ)

fclean: clean
		@echo "\033[96mSuppression de l'executable rtv1"
		@rm -f $(NAME)

clean_ft:
		@make clean -C libft
		@echo "\033[96mSuppression des objets du rtv1"
		@rm -f $(OBJ)

fclean_ft: clean_ft
		@make fclean -C libft
		@echo "\033[96mSuppression de l'executable rtv1"
		@rm -f $(NAME)

re: fclean all

re_ft: fclean_ft all

.PHONY: all clean fclean re clean_ft fclean_ft re_ft
