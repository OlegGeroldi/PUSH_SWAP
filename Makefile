NAME    = push_swap
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -I.

# Здесь перечисляем ВСЕ твои .c файлы
SRC     = main.c \
          stack_utils.c \
          operations_push.c \
          operations_rotate.c \
		  operations_rev_rotate.c \
		  operations_swap.c \
		  sort_small.c \
		  sort_big.c \
          validation.c \
		  index.c \

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

# Это правило учит Makefile пересобирать объекты, если изменился хедер
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re