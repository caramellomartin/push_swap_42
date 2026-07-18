NAME        = push_swap
CHECKER = checker
CC          = cc
CFLAGS      = -Wall -Werror -Wextra
RM          = rm -f

SRC         = main.c \
              parsing.c \
	      parsing_utils.c \
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

CHECKER_SRC = checker.c  \
                get_next_line.c  \
                get_next_line_utils.c  \
              	parsing.c \
	      	parsing_utils.c \
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

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

all: $(NAME) $(CHECKER)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) -o $(CHECKER)

%.o: %.c Makefile push_swap.h checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(CHECKER_OBJ)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
