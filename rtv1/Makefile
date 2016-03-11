# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 16:51:55 by svelhinh          #+#    #+#              #
#    Updated: 2016/03/11 12:04:35 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC2 = main.c events.c parser.c render.c vectors.c init_objects.c init_all.c \
	   objects.c intersections.c functions.c

SRC = $(addprefix srcs/, $(SRC2))

LIB = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

INCLUDES = includes

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

SHELL = ZSH

all: $(NAME)
	@echo "\033[0m"

$(NAME): rtv $(OBJ)
		@echo -n "\n\033[33mLIBFT : \033[0m"
		@make -C libft
		@gcc -o $(NAME) $(OBJ) $(LIB) $(LIBFT) -Wall -Wextra -Werror -g

%.o: %.c
		@echo -n "\033[32m="
		@gcc -o $@ -c $< -Wall -Wextra -Werror -I $(INCLUDES)

rtv:
		@echo -n "\033[32mRTV1 : "

clean:
		@echo "\033[32mSuppression des objets du rtv1\033[0m"
		@rm -f $(OBJ)

fclean: clean
		@echo "\033[32mSuppression de l'executable du rtv1\033[0m"
		@rm -f $(NAME)

clean_ft: clean
		@make clean -C libft

fclean_ft: fclean
		@make fclean -C libft

re: fclean all

re_ft: fclean_ft all

.PHONY: all clean fclean re clean_ft fclean_ft re_ft
