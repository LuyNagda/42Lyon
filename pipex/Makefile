# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 13:52:39 by lunagda           #+#    #+#              #
#    Updated: 2023/12/11 13:36:31 by lunagda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS	=	main.c error.c utils/ft_strdup.c utils/ft_split.c utils/ft_free.c utils/ft_strjoin.c \
			utils/ft_strncmp.c parsing/parsing_for_path.c parsing/get_path.c parsing/pipex.c \
			utils/get_next_line_utils.c utils/get_next_line.c utils/ft_strcmp.c

OBJS	=	$(SRCS:.c=.o)

HEADER	=	pipex.h
GNL_HEADER = utils/get_next_line.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I includes -g3

all: ${NAME}

$(OBJS): $(HEADER)
$(OBJS): $(GNL_HEADER)

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

