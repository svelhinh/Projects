# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 15:53:58 by svelhinh          #+#    #+#              #
#    Updated: 2017/09/20 18:42:21 by svelhinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM			= 	nasm
ASM_FLAGS	= 	-f macho64
AR			= 	ar
AR_FLAGS	= 	rc
RANLIB		= 	ranlib
SRC			=	ft_tolower.s ft_toupper.s ft_isprint.s ft_isascii.s ft_isdigit.s \
				ft_isalpha.s ft_isalnum.s ft_puts.s ft_islower.s ft_isupper.s ft_strlen.s \
				ft_bzero.s ft_strcat.s ft_memset.s ft_memcpy.s ft_strdup.s ft_cat.s
OBJ			= 	$(SRC:.s=.o)
NAME		= 	libfts.a
SHELL		= 	ZSH

all: $(NAME)
	@echo -n ""

$(NAME): $(OBJ)
	@$(AR) $(AR_FLAGS) $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)

%.o: %.s
	@$(ASM) $(ASM_FLAGS) $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all