NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f

SRCS = src/pipex.c src/executor.c src/parser.c src/error_handler.c src/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./Libft -lft

libft:
	make -C ./Libft

clean:
	$(RM) $(OBJS)
	make clean -C ./Libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./Libft

re: fclean all

.PHONY: all clean fclean re libft