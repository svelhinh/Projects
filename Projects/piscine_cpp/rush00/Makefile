# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 15:07:52 by svelhinh          #+#    #+#              #
#    Updated: 2017/04/09 20:41:37 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

SRC_PATH = src

OBJ_PATH = obj

CFLAGS = -Wall -Wextra -Werror -I./includes

NCURSESFLAGS = -lncurses

NAME = ft_retro

SRC_NAME =	ACharacter.cpp Enemy.cpp Event.cpp Game.cpp main.cpp Player.cpp \
			UserInterface.cpp AHitBox.cpp Missile.cpp

OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

ifneq ($(shell uname), Linux)
SHELL = ZSH
endif

all: $(NAME)
	@echo -n "\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@ $(NCURSESFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo -n "\033[94m"
	@echo $<
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@echo "\033[91mObj deleted\033[0m"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "\033[91mExecutable deleted\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all rtv
