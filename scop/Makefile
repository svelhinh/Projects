# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 16:43:09 by svelhinh          #+#    #+#              #
#    Updated: 2018/06/08 18:28:30 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= scop
CC		= gcc

SRC_PATH	= ./srcs/
OBJ_PATH	= ./objs/
LIBS_PATH	= ./libs/
INC_PATH	= ./includes/ $(LIBS_PATH)libft/includes/ $(LIBS_PATH)glfw/include/GLFW $(LIBS_PATH)glew/include/GL

GCC_FLAGS = -Wall -Wextra -Werror
GCC_LIBS = -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

SRC_NAME = main.c init.c window.c shaders.c events.c logs.c logs2.c errors.c utils.c parsing.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft/libft.a glfw/src/libglfw3.a glew/lib/libGLEW.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix $(LIBS_PATH),$(LIB_NAME))

OS := $(shell uname)



CURRENT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

all: $(NAME)

$(NAME): libs $(OBJ)
	$(CC) $(GCC_FLAGS) -o $(NAME) $(OBJ) $(LIB) $(GCC_LIBS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(GCC_FLAGS) $(INC) -o $@ -c $<


libs: libft glew glfw
#ifeq ($(OS), Darwin)		
	if ! [ -f ./libs/glew/lib/libGLEW.a ]; then \
		make -C libs/glew extensions; \
		make -C libs/glew; \
	fi
#else
#	sudo aptitude install libxi-dev libxmu-dev
# 	sudo apt install build-essential libgl1-mesa-dev freeglut3-dev
# 	cd libs/glew/build && cmake ./cmake && make -j4
# endif

libft:
	make -C libs/libft

glew:
	cd libs && git clone https://github.com/nigels-com/glew.git || true

glfw: cmake
# ifeq ($(OS), Darwin)		
	cd libs && git clone https://github.com/glfw/glfw.git || true
	if ! test -f libs/glfw/src/libglfw3.a; \
	then \
		cd libs/glfw && cmake . && make || true; \
	fi
#else
	# cd libs && git clone https://github.com/glfw/glfw.git || true
	# if ! test -f libs/glfw/src/libglfw3.a; \
	# then \
	# 	sudo apt-get install xorg-dev libglu1-mesa-dev \
	# 	cd libs/glfw && cmake . && make || true; \
	# fi
# endif

cmake:
# ifeq ($(OS), Darwin)
	brew install cmake
# else
# 	sudo apt install cmake
# endif

clean:
	@rm -rf $(OBJS)

fcleanall: clean
	make fclean -C $(LIBS_PATH)/libft
	rm -rf libs/glew libs/glfw libs/cmake-3.4.1-Darwin-x86_64 libs/cmake-3.4.1-Darwin-x86_64.tar.gz
	rm -rf $(NAME)

reall: fcleanall all

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean re all libs
