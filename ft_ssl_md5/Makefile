# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/03 17:30:56 by svelhinh          #+#    #+#              #
#    Updated: 2018/07/23 19:17:55 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ssl
CC		= gcc

SRC_PATH	= ./srcs/
OBJ_PATH	= ./objs/
LIBS_PATH	= ./libs/
INC_PATH	= ./includes/ $(LIBS_PATH)libft/includes/

GCC_FLAGS = -Wall -Wextra -Werror

SRC_NAME =	main.c md5.c md5_init.c md5_hash.c sha256.c sha256_init.c sha256_hash.c \
			utils.c errors.c parsing.c print_msg.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft/libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix $(LIBS_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(GCC_FLAGS) -o $(NAME) $(OBJ) $(LIB) -lm

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(GCC_FLAGS) $(INC) -o $@ -c $<


libft:
	make -C libs/libft

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C libs/libft
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean re all libft
