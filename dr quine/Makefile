CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

NAME = Colleen

NAME2 = Grace

NAME3 = Sully

SRC = Colleen.c

SRC2 = Grace.c

SRC3 = Sully.c

OBJ = $(SRC:.c=.o)

OBJ2 = $(SRC2:.c=.o)

OBJ3 = $(SRC3:.c=.o)

SHELL = ZSH

all: $(NAME) $(NAME2) $(NAME3)
	@echo -n "\033[0m"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@echo $(NAME)

$(NAME2): $(OBJ2)
	@gcc -o $(NAME2) $(OBJ2) $(CFLAGS)
	@echo $(NAME2)

$(NAME3): $(OBJ3)
	@gcc -o $(NAME3) $(OBJ3) $(CFLAGS)
	@echo $(NAME3)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ) $(OBJ2) $(OBJ3)

fclean: clean
	@rm -rf $(NAME) $(NAME2) $(NAME3)

re: fclean all

.PHONY: clean fclean re all
