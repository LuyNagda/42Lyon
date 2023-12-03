# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 00:13:57 by luynagda          #+#    #+#              #
#    Updated: 2023/12/02 23:31:44 by luynagda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = push_swap_checker

SRCS = solving/both_stack_different.c solving/both_stack.c solving/solve_for_3_4_5.c solving/solve.c utils/check_for_errors.c utils/ft_split.c utils/ft_strchr.c utils/ft_strict_atoi.c utils/get_cheapest.c utils/initialize.c utils/is_sorted.c utils/lst_functions.c utils/operations.c utils/push_swap_operations.c utils/rev_rotate_operations.c utils/rotate_operations.c utils/utils.c main.c
CHECKER_SRCS = utils/check_for_errors.c utils/ft_split.c utils/ft_strchr.c utils/ft_strict_atoi.c utils/initialize.c utils/is_sorted.c utils/lst_functions.c utils/operations.c utils/utils.c checker/get_next_line_utils.c checker/get_next_line.c checker/checker.c

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

HEADER = push_swap.h
CHECKER_HEADER = checker/get_next_line.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -I includes

all: ${NAME}

$(OBJS): $(HEADER)
$(CHECKER_OBJS): $(HEADER) $(CHECKER_HEADER)

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus:	${CHECKER}

${CHECKER}: ${CHECKER_OBJS} 
	${CC} ${CFLAGS} ${CHECKER_OBJS} -o ${CHECKER}

clean: 
	${RM} ${OBJS}
	${RM} ${CHECKER_OBJS}

fclean: clean
	${RM} ${NAME} ${CHECKER}

re: fclean all

.PHONY: all clean fclean re