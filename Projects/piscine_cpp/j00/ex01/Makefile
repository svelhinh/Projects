# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 12:03:06 by svelhinh          #+#    #+#              #
#    Updated: 2017/04/03 12:19:52 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++ -Wall -Wextra -Werror

OBJ_PATH = obj

NAME = phonebook

SRC_NAME =	main.cpp Contact.class.cpp

OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(SRC_NAME)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

ifneq ($(shell uname), Linux)
SHELL = ZSH
endif

all: $(NAME)
	@echo "\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@

$(OBJ_PATH)/%.o: %.cpp
	@echo -n "\033[32m=\033[0m"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@echo "\033[32mObjects deleted\033[0m"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "\033[32mExecutable deleted\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
