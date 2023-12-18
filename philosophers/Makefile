# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 12:02:11 by lunagda           #+#    #+#              #
#    Updated: 2023/12/18 13:08:39 by lunagda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

SRC		=	src/philo.c		\
			src/ft_utils.c

HEADER	=	./includes/philo.h

INC_DIR	=	./includes/

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(OBJ):		$(HEADER)

$(NAME):	$(OBJ)
	$(CC) $(FLAG) -I$(INC_DIR) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re