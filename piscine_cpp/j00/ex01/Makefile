# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 18:24:41 by lnieto-m          #+#    #+#              #
#    Updated: 2016/05/13 19:07:45 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++ -Wall -Wextra -Werror

SRC_PATH = srcs

OBJ_PATH = obj

CPFLAGS = -I ./includes

NAME = phonebook

SRC_NAME =	main.cpp Contact.class.cpp

OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

ifneq ($(shell uname), Linux)
SHELL = ZSH
endif

all: $(NAME)
	@echo "\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo -n "\033[32m=\033[0m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPFLAGS) -o $@ -c $<

clean:
	@echo "\033[32mObjects deleted\033[0m"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "\033[32mExecutable deleted\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
