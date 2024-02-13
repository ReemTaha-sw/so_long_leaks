NAME = libftprintf.a

SRC = ft_printf.c 			\
		ft_print_char.c 	\
		ft_print_string.c 	\
		ft_print_digit.c 	\
		ft_print_pointer.c 	\
		ft_print_unsigned.c \
		

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@ ar -rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re