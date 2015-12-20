# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 11:07:36 by sacerise          #+#    #+#              #
#    Updated: 2015/12/20 13:26:49 by sacerise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=alcu

CC=gcc

CFLAGS=-Wall -Wextra -Werror 

RM=rm -f

LIB= libft/libft.a

OBJ

all: $(NAME)

%.o: %.c alcu.h
	$(CC) $(CFLAGS) -libft -o $@ $< -c

$(NAME): $(OBJ) $(LIB)
	ar rc $@ $+
	ranlib $@

.PHONY: clean fclean re all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all