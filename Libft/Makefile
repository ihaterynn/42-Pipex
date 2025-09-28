SRCS_MANDATORY = ft_atoi.c \
                ft_bzero.c \
                ft_calloc.c \
                ft_memchr.c \
                ft_memcmp.c \
                ft_memcpy.c \
                ft_memmove.c \
                ft_strdup.c \
                ft_strjoin.c \
                ft_strlcat.c \
                ft_strlcpy.c \
                ft_strlen.c \
                ft_strnstr.c \
                ft_substr.c \
                ft_isalpha.c \
                ft_isdigit.c \
                ft_isalnum.c \
                ft_isascii.c \
                ft_isprint.c \
                ft_memset.c \
                ft_toupper.c \
                ft_tolower.c \
                ft_strchr.c \
                ft_strrchr.c \
                ft_strncmp.c \
                ft_strtrim.c \
                ft_split.c \
                ft_itoa.c \
                ft_strmapi.c \
                ft_striteri.c \
                ft_putchar_fd.c \
                ft_putstr_fd.c \
                ft_putendl_fd.c \
                ft_putnbr_fd.c

# Object files
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)

# Compiler and tools
CC = gcc
AR = ar
RM = rm -f

# Flags
CFLAGS = -Wall -Wextra -Werror -I.
ARFLAGS = rcs

# Library name
NAME = libft.a

# Default target: builds the library with mandatory functions
all: $(NAME)

# Rule to build the library with mandatory functions
# This target means "the file $(NAME) depends on $(OBJS_MANDATORY)"
$(NAME): $(OBJS_MANDATORY)
	@echo "Archiving mandatory functions into $(NAME)..."
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_MANDATORY)
	@echo "$(NAME) with mandatory functions is ready."

# Rule to compile .c files to .o files (generic pattern rule)
# This rule will be used to build any .o file from its .c source
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "Cleaning object files..."
	$(RM) $(OBJS_MANDATORY)
	@echo "Object files cleaned."

# Clean object files and the library
fclean: clean
	@echo "Cleaning $(NAME)..."
	$(RM) $(NAME)
	@echo "$(NAME) cleaned."

# Rebuild everything
re: fclean all bonus

.PHONY: all bonus clean fclean re
