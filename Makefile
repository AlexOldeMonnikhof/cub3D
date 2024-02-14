# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:37:39 by aolde-mo          #+#    #+#              #
#    Updated: 2024/02/14 16:23:55 by aolde-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
LIBFT = libft/libft.a
SRC = main.c init_utils.c utils.c init.c raycasting.c draw.c utils2.c hooks.c \
		error_check.c get_next_line_utils.c final_parse.c get_next_line.c parsing.c \
		allocate_map.c check_map.c check_player.c check_top_end.c check_top.c \
		parsing_utils.c pars_start.c get_start_point.c cleanup.c parsing_utils2.c
VPATH = src src/execute src/parsing
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR = obj
CFLAGS = -Ofast -fsanitize=address -g -Wall -Wextra -Werror
USER = $(shell whoami)
LIBMLX = MLX42
LIBS = $(LIBMLX)/build/libmlx42.a -L/Users/$(USER)/.brew/opt/glfw/lib -lglfw -ldl -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit

CC = gcc

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME) : $(OBJ) $(LIBFT) inc/cub3d.h
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(LIBFT) -o $(NAME)
	@printf "$(NAME) compiled\n"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean:
	@rm -rf $(OBJ_DIR) $(NAME)
	@make -C libft fclean

re: fclean all

PHONY: all clean fclean re