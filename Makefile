CC = cc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = -rc

FUNCTIONS = 

libft.a:


clean:
	@rm -f *.o

fclean: clean
	@rm -f $(TARGET)

re: fclean all

.PHONY: re all clean fclean