# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 23:34:38 by akhalid           #+#    #+#              #
#    Updated: 2020/01/04 07:27:16 by akhalid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -rf

NAME = libftprintf.a

SRCS =	ft_printf.c		\
		format_handler.c	\
		libft_printf1.c	\
		libft_printf2.c	\
		libft_printf3.c	\
		int.c			\
		unsignedint.c	\
		str_char.c		\
		pointer.c		\
		tools.c			\
		
OBJS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(OBJS) $(SRCS)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all