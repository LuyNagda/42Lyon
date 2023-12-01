# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 00:13:57 by luynagda          #+#    #+#              #
#    Updated: 2023/12/01 21:12:16 by luynagda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = solving/both_stack_different.c solving/both_stack.c solving/solve_for_3_4_5.c solving/solve.c utils/check_for_errors.c utils/ft_split.c utils/ft_strchr.c utils/ft_strict_atoi.c utils/get_cheapest.c utils/initialize.c utils/is_sorted.c utils/lst_functions.c utils/operations.c utils/push_swap_operations.c utils/rev_rotate_operations.c utils/rotate_operations.c utils/utils.c main.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -I includes

all: ${NAME}

$(OBJS): $(HEADER)

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re