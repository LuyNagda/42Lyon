# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 00:13:57 by luynagda          #+#    #+#              #
#    Updated: 2023/11/28 21:39:42 by luynagda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(wildcard solving/*.c utils/*.c *.c)

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