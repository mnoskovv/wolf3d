# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 16:48:50 by mnoskov           #+#    #+#              #
#    Updated: 2018/08/15 13:29:12 by mnoskov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d

LIB_DIR := ./libft/
SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/

SRC := main.c exit_errors.c window.c keys.c raycast.c read_map.c validation.c prepare.c helpers.c texture_loader.c walls_floor_roof.c sound.c
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC := gcc
FLAGS := -Wall -Wextra -Werror -O2

FRMWR := -framework OpenGL -framework AppKit
MLX_LIB := -L /usr/local/lib/ -lmlx
LIBFT = $(LIB_DIR)libft.a
LIBFT_FLAGS := -L $(LIB_DIR) -lft
LIBFT_INC := $(LIB_DIR)incs

HDR_FLAGS := -I $(LIBFT_INC) -I $(INC_DIR) -I /usr/locale/include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(HDR_FLAGS) -o $(NAME) $(LIBFT) $(FRMWR) $(MLX_LIB)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ $(FLAGS) $(HDR_FLAGS)

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean:
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all