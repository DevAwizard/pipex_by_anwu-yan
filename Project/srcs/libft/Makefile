NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_FILES = ft_atoi.c \
            ft_bzero.c \
            ft_calloc.c \
            ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isprint.c \
            ft_itoa.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memmove.c \
            ft_memset.c \
            ft_putchar_fd.c \
            ft_putendl_fd.c \
            ft_putnbr_fd.c \
            ft_putstr_fd.c \
            ft_split.c \
            ft_strchr.c \
            ft_strdup.c \
            ft_striteri.c \
            ft_strjoin.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strmapi.c \
            ft_strncmp.c \
            ft_strnstr.c \
            ft_strrchr.c \
            ft_strtrim.c \
            ft_substr.c \
            ft_tolower.c \
            ft_toupper.c \
            ft_printf.c \
            ft_printf_utils.c \
            ft_find_max_int.c \
            ft_find_min_int.c \
            ft_strndup.c \
            ft_strncpy.c \
            ft_ascii_new.c \
            ft_strcmp.c

HEADER = libft.h
LIBC = ar rcs

OBJS = $(SRC_FILES:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@printf "\e[31m*.o=>🗑️\e[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\e[31m(libft.a)=>🗑️\e[0m\n"

re: fclean all

.PHONY: all clean fclean re
