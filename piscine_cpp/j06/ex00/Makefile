# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/27 16:31:26 by svelhinh          #+#    #+#              #
#    Updated: 2016/06/27 16:40:58 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++ -Wall -Wextra -Werror

NAME = convert

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

SHELL = ZSH

all: $(NAME)
	@echo "\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@

%.o: %.cpp
	@echo -n "\033[32m=\033[0m"
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
