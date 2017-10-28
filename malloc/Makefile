# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 11:40:57 by svelhinh          #+#    #+#              #
#    Updated: 2017/05/11 16:11:01 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
    HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CC = gcc

SRC_PATH = srcs

OBJ_PATH = objs

CFLAGS = -g -Wall -Wextra -Werror

INCLUDES = -I./libft/includes -I./includes

SRC_NAME =	malloc.c find.c create_areas.c print_memory.c free.c realloc.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIB_NAME = libft_malloc_$(HOSTTYPE).so

SYM_LINK_NAME = libft_malloc.so

ifneq ($(shell uname), Linux)
SHELL = ZSH
endif

all: $(LIB_NAME)
		@echo "\033[36mCreating symbolic link for malloc library\033[32m"
		@echo $<
		@ln -s $< $(SYM_LINK_NAME)
		@echo -n "\033[0m"

$(LIB_NAME): $(OBJ)
		@echo "\033[36mCompiling libft\033[32m"
		@make -C libft
		@echo "\033[36mCreating malloc library\033[32m"
		@echo $^
		@$(CC) -shared -fPIC $^ -Llibft -lft -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@echo -n "\033[32m"
		@echo $<
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(CFLAGS) -c $^ $(INCLUDES) -o $@

clean:
		@echo "\033[31mRemove malloc object files\033[0m"
		@make -C libft clean
		@rm -rf $(OBJ_PATH)

fclean: clean
		@echo "\033[31mRemove malloc library\033[0m"
		@make -C libft fclean
		@rm -rf $(LIB_NAME)
		@rm -rf $(SYM_LINK_NAME)

re: fclean all

.PHONY: all clean fclean re
