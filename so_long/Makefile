# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 15:59:25 by lunagda           #+#    #+#              #
#    Updated: 2023/12/23 13:01:08 by lunagda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

NAME_BONUS	=	so_long_bonus

CC			=	gcc

FLAG		=	-Wall -Wextra -Werror -g

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

MLX_FILE	=	libmlx_Linux.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FLAG	=	-lX11 -lXext

MLX_PATH	=	./minilibx-linux/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	main.c				\
				ft_utils.c			\
				ft_init_map.c		\
				ft_check_map.c		\
				ft_map_valid.c		\
				ft_init_mlx.c		\
				ft_render_map.c		\
				ft_close.c			\
				ft_handle_keypress.c

BONUS_FILE	=	main_bonus.c				\
				ft_utils_bonus.c			\
				ft_init_map_bonus.c			\
				ft_check_map_bonus.c		\
				ft_map_valid_bonus.c		\
				ft_init_mlx_bonus.c			\
				ft_render_map_bonus.c		\
				ft_close_bonus.c			\
				ft_handle_keypress_bonus.c

SRC_DIR		=	./src/
BONUS_DIR	=	./src_bonus/

HEADER		=	./includes/so_long.h

BONUS_HEADER=	./src_bonus/so_long_bonus.h

INC_DIR		=	./includes/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE)) gnl/get_next_line.c gnl/get_next_line_utils.c
SRC_BONUS	=	$(addprefix $(BONUS_DIR),$(BONUS_FILE)) gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ			=	$(SRC:.c=.o)
BONUS_OBJ	=	$(SRC_BONUS:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@ -I$(INC_DIR)

all: $(NAME)

lib:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

mlx:
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"

$(NAME): lib mlx $(OBJ)
	@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m./so_long created\n"

$(OBJ):	$(HEADER)
$(BONUS_OBJ):	$(BONUS_HEADER)

bonus: lib mlx $(BONUS_OBJ)
	@echo "\033[0;33m\nCOMPILING SO_LONG BONUS...\n"
	$(CC) $(BONUS_OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME_BONUS)
	@echo "\033[1;32m./so_long_bonus created\n"

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting So_long object...\n"
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting So_long_bonus object...\n"
	@rm -f $(BONUS_OBJ)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable..."
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re bonus