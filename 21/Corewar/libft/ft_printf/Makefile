# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/24 11:01:01 by dphyliss          #+#    #+#              #
#    Updated: 2021/01/05 11:49:48 by dphyliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	print_dec.c \
		print_unsigned.c \
		print_hex.c \
		print_octal.c \
		print_percent.c \
		print_string.c \
		print_char.c \
		print_uni_string.c \
		is_functions.c \
		help_functions.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror


all: $(OBJ)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
