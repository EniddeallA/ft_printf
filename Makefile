# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 23:34:38 by akhalid           #+#    #+#              #
#    Updated: 2020/01/20 08:47:28 by akhalid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -rf

NAME = libftprintf.a

SRCS =	ft_printf/ft_printf.c				\
		ft_printf/format_handler.c			\
		ft_libft/libft_printf1.c			\
		ft_libft/libft_printf2.c			\
		ft_libft/libft_printf3.c			\
		convertion_Parsers/int.c			\
		convertion_Parsers/unsignedint.c	\
		convertion_Parsers/str_char.c		\
		convertion_Parsers/pointer.c		\
		convertion_Parsers/tools.c			\
		
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
