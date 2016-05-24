CC = g++

CFLAGS = -Wall -Wextra -Werror

NAME = replace

SRC =	replace.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
		@echo -n "\033[0m"

$(NAME): $(OBJ)
		@$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

%.o: %.c
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
