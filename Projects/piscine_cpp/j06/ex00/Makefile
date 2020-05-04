# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 15:07:52 by svelhinh          #+#    #+#              #
#    Updated: 2017/04/11 17:17:41 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

CFLAGS = -Wall -Wextra

NAME = scalar

SRC =	main.cpp

OBJ = $(SRC:.cpp=.o)

ifneq ($(shell uname), Linux)
SHELL = ZSH
endif

all: $(NAME)
	@echo -n "\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@

%.o: %.cpp
	@echo -n "\033[94m"
	@echo $<
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@echo "\033[91mObj deleted\033[0m"
	@rm -rf $(OBJ)

fclean: clean
	@echo "\033[91mExecutable deleted\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all rtv
