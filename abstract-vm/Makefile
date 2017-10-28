# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 11:40:57 by svelhinh          #+#    #+#              #
#    Updated: 2017/05/31 12:52:02 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

ifneq ($(shell uname), Linux)
SHELL = ZSH
CFLAGS = -Wall -Wextra -Werror -Wno-c++11-extensions -g
else
CFLAGS = -Wall -Wextra -Werror -std=c++11 -g
endif

NAME = abstract-vm

INCLUDES = includes

SRC_PATH = srcs

OBJ_PATH = objs

SRC_NAME = main.cpp Init.cpp Memory.cpp Parser.cpp Exception.cpp

OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)
		@echo -n "\033[0m"

$(NAME): $(OBJ)
		@$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
		@echo -n "\033[32m"
		@echo $<
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
		@echo "\033[32mRemove objects\033[0m"
		@rm -f $(OBJ)
		@rm -rf $(OBJ_PATH)

fclean: clean
		@echo "\033[32mRemove executable\033[0m"
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
