CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
ARFLAGS		= -rc
SRC			= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_memmove.c
OBJ			= $(SRC:.c=.o)
BSRC		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BOBJ		= $(BSRC:.c=.o)
NAME		= libft.a
HEADER		= libft.h

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	ar $(ARFLAGS) $(NAME) $(OBJ)

bonus: $(NAME)
	$(CC) $(CFLAGS) -c $(BSRC)
	ar $(ARFLAGS) $(NAME) $(BOBJ)

all: $(NAME) bonus

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: re all clean fclean
