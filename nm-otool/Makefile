# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 15:07:52 by svelhinh          #+#    #+#              #
#    Updated: 2017/08/09 16:49:42 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_NM			= ft_nm
NAME_OTOOL		= ft_otool

CC				= gcc
FLAGS			= -g -Wall -Werror -Wextra

SRC_PATH		= srcs
NM_SRC_PATH		= $(SRC_PATH)/nm
OTOOL_SRC_PATH	= $(SRC_PATH)/otool

UTILS_SRC_NAME	= ../utils.c ../utils_32.c ../utils_64.c

NM_SRC_NAME		= nm.c sort.c handle_64.c get_syms_64.c get_sects_64.c handle_32.c get_syms_32.c get_sects_32.c handle_fat.c $(UTILS_SRC_NAME)

OBJ_PATH		= objs
NM_OBJ_PATH		= $(OBJ_PATH)/nm
OTOOL_OBJ_PATH	= $(OBJ_PATH)/otool

OTOOL_SRC_NAME	= otool.c handle_64_otool.c get_text_sect_64.c get_lines_64.c handle_32_otool.c get_text_sect_32.c get_lines_32.c handle_fat_otool.c get_lines.c $(UTILS_SRC_NAME)

NM_SRCS			= $(addprefix $(NM_SRC_PATH)/, $(NM_SRCS_NAME))
OTOOL_SRCS		= $(addprefix $(OTOOL_SRC_PATH)/, $(OTOOL_SRCS_NAME))
NM_OBJ_NAME		= $(NM_SRC_NAME:.c=.o)
OTOOL_OBJ_NAME	= $(OTOOL_SRC_NAME:.c=.o)
NM_OBJS			= $(addprefix $(NM_OBJ_PATH)/, $(NM_OBJ_NAME))
OTOOL_OBJS		= $(addprefix $(OTOOL_OBJ_PATH)/, $(OTOOL_OBJ_NAME))

LIBFT_PATH		= libft

NM_INCS			= -I ./includes/nm -I ./includes/other -I ./$(LIBFT_PATH)/includes
OTOOL_INCS		= -I ./includes/otool -I ./includes/other -I ./$(LIBFT_PATH)/includes
LIBS			= ./$(LIBFT_PATH)/libft.a

all: createobjpath $(NAME_NM) $(NAME_OTOOL)

SHELL = ZSH

$(NAME_NM): $(NM_OBJS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(LIBFT_PATH)/libft.a $(FLAGS) $(NM_OBJS) -o $@

$(NAME_OTOOL): $(OTOOL_OBJS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(LIBFT_PATH)/libft.a $(FLAGS) $(OTOOL_OBJS) -o $@

$(NM_OBJ_PATH)/%.o: $(NM_SRC_PATH)/%.c
	@echo -n "\033[94m"
	@echo $<
	@mkdir $(NM_OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -c $^ $(NM_INCS) -o $@

$(OTOOL_OBJ_PATH)/%.o: $(OTOOL_SRC_PATH)/%.c
	@echo -n "\033[94m"
	@echo $<
	@mkdir $(OTOOL_OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -c $^ $(OTOOL_INCS) -o $@

createobjpath:
	@mkdir -p $(OBJ_PATH)

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -rf $(NM_OBJ_PATH)
	@echo "\033[91mft_nm objs deleted\033[0m"
	@rm -rf $(OTOOL_OBJ_PATH)
	@echo "\033[91mft_otool objs deleted\033[0m"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME_NM)
	@echo "\033[91mft_nm executable deleted\033[0m"
	@rm -rf $(NAME_OTOOL)
	@echo "\033[91mft_otool executable deleted\033[0m"

re: fclean all

.PHONY: clean fclean re all
