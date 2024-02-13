# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosman <rosman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 20:20:55 by rosman            #+#    #+#              #
#    Updated: 2024/02/13 20:47:15 by rosman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFTft_printf	= ft_printf/libftprintf.a

SRC = main.c \
		util.c\
		parsing.c\
		git_next_line/get_next_line.c \
		git_next_line/get_next_line_utils.c \
		draw.c \
		check_map.c \
		exit_game.c \
		is_valid_map.c \
		animate_collect.c \
		init_data.c \
		update_game.c \
		enemy.c \
		ft_itoa.c

SRC_B = bonus.c \
		util.c\
		parsing.c\
		git_next_line/get_next_line.c \
		git_next_line/get_next_line_utils.c \
		draw.c \
		check_map.c \
		is_valid_map.c \
		exit_game.c \
		animate_collect.c \
		init_data.c \
		update_game.c \
		draw_bonus.c \
		bonus_update_game.c \
		enemy.c \
		extra_fun_bonus.c \
		ft_itoa.c
		

CC = cc

CFLAGS  = -Wall -Wextra -Werror
# -g3 -fsanitize=address

MLXLINKER = -Llibx -lmlx -framework OpenGL -framework AppKit


OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	cd ft_printf && make
	cd libx && make
	$(CC) $(CFLAGS) $(OBJ) $(MLXLINKER) $(LIBFTft_printf) -o $(NAME)
	
bonus: $(OBJ_B)
	@ cd ft_printf && make
	@ cd libx && make
	$(CC) $(CFLAGS) $(OBJ_B) $(MLXLINKER) $(LIBFTft_printf) -o $(NAME)
# $(CC) $(CFLAGS) $(OBJ_B) $(MLXLINKER) $(LIBFTft_printf) -o $(NAME) 

all: $(NAME)

clean:
	cd ft_printf && make clean
	# @ cd libx && make clean
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	cd ft_printf && make fclean
	rm -f $(LIBFTft_printf)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



# cd ft_printf && make
# @$(MAKE)  -C ./ft_printf

# cd ft_printf && make clean
# @$(MAKE) clean -C ./ft_printf

# cd ft_printf && make fclean
# @$(MAKE)  fclean -C ./ft_printf