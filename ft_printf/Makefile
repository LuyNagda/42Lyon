# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 11:12:10 by lunagda           #+#    #+#              #
#    Updated: 2023/11/11 14:41:53 by lunagda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_print_hexa.c ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_strlen.c ft_print_unsigned.c ft_print_ptr.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
HEADER			= ft_printf.h

NAME			= libftprintf.a

all:			$(NAME)

$(OBJS):		$(HEADER)
$(BONUS_OBJS):	$(HEADER)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re