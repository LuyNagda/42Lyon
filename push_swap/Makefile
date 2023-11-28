# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 00:13:57 by luynagda          #+#    #+#              #
#    Updated: 2023/11/28 15:26:00 by lunagda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(wildcard solving/*.c utils/*.c *.c)

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes

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