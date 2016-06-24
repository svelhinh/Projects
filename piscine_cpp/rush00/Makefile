# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 18:24:41 by lnieto-m          #+#    #+#              #
#    Updated: 2016/06/23 11:37:34 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

SRC_PATH = srcs

OBJ_PATH = obj

CPPFLAGS = -Wall -Wextra -Werror

LFLAGS = -lncurses

NAME = ft_retro

SRC_NAME =	main.cpp Ship.cpp AWeapon.cpp PlasmaRifle.cpp Game.cpp Enemy.cpp

OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

SHELL = ZSH

all: $(NAME)
	@echo "\033[0m"

$(NAME): retro $(OBJ)
	@$(CC) $(LFLAGS) $(OBJ) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo -n "\033[32m="
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $< -I includes

retro:
	@echo -n "\033[32mFT_RETRO : "

clean:
	@echo "\033[32mSuppression des objets\033[0m"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "\033[32mSuppression de l'executable\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all retro
