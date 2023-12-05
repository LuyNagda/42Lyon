# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 13:52:39 by lunagda           #+#    #+#              #
#    Updated: 2023/12/05 13:40:55 by lunagda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS	=	main.c utils/ft_strdup.c utils/ft_split.c utils/ft_free.c utils/ft_strjoin.c \
			utils/ft_strncmp.c parsing/parsing_for_path.c parsing/get_path.c files/access_file.c \
			parsing/get_piped_commands.c parsing/pipex.c

OBJS	=	$(SRCS:.c=.o)

HEADER	=	pipex.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I includes

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

