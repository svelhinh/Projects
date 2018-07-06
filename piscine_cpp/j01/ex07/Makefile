# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 11:40:57 by svelhinh          #+#    #+#              #
#    Updated: 2017/04/04 19:00:14 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

CFLAGS = -Wall -Wextra -Werror

NAME = replace

SRC =	replace.cpp

OBJ = $(SRC:.cpp=.o)

ifneq ($(shell uname), Linux)
SHELL = ZSH
endif

all: $(NAME)
		@echo -n "\033[0m"

$(NAME): $(OBJ)
		@$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

%.o: %.cpp
		@echo -n "\033[32m="
		@$(CC) -o $@ -c $< $(CFLAGS)

clean:
		@echo "\033[32mObjects deleted\033[0m"
		@rm -f $(OBJ)

fclean: clean
		@echo "\033[32mExecutable deleted\033[0m"
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
