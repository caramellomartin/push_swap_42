NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Werror -Wextra
RM          = rm -f

SRC         = main.c \
              parsing.c \
              split.c \
              stack.c \
              utils.c \
              print_utils.c \
              bench.c \
              swap.c \
              push.c \
              rotate.c \
              reverse_rotate.c \
              index.c \
              disorder.c \
              sort.c \
              sort_simple.c \
              sort_medium.c \
              sort_complex.c

OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
