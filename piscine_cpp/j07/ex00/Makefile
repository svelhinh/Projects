# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/27 16:31:26 by svelhinh          #+#    #+#              #
#    Updated: 2016/06/28 11:50:38 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++ -Wall -Wextra -Werror

NAME = iter

SRC = iter.cpp

OBJ = $(SRC:.cpp=.o)

SHELL = ZSH

all: $(NAME)
	@echo -n "\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@

%.o: %.cpp
	@echo -n "\033[93m"
	@echo -n $<
	@$(CC) -o $@ -c $<
	@echo "\033[92m				✓\033[0m"

clean:
	@echo "\033[96mObjects deleted\033[0m"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "\033[96mExecutable deleted\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
