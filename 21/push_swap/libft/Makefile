# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 17:28:47 by jkrypto           #+#    #+#              #
#    Updated: 2019/12/14 19:08:56 by jkrypto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

INC_DIR	=	./inc/
SRC_DIR	=	./src/
OBJ_DIR	=	./obj/

INC		=	libft.h

SRC		=	ft_memalloc.c ft_strdup.c ft_memccpy.c ft_strequ.c ft_memchr.c	\
			ft_striter.c ft_memcmp.c ft_striteri.c ft_atoi.c ft_memcpy.c	\
			ft_strjoin.c ft_bzero.c ft_memdel.c ft_strlcat.c ft_delint.c	\
			ft_memmove.c ft_strlen.c ft_digitcount.c ft_memrcpy.c			\
			ft_strmap.c ft_isalnum.c ft_memset.c ft_strmapi.c ft_isalpha.c	\
			ft_putchar.c ft_strncat.c ft_isascii.c ft_putchar_fd.c			\
			ft_strncmp.c ft_isdigit.c ft_putendl.c ft_strncpy.c				\
			ft_islower.c ft_putendl_fd.c ft_strnequ.c ft_isprint.c			\
			ft_putnbr.c ft_strnew.c ft_isspace.c ft_putnbr_fd.c				\
			ft_strnstr.c ft_isupper.c ft_putstr.c ft_strrchr.c ft_itoa.c	\
			ft_putstr_fd.c ft_strsplit.c ft_lstadd.c ft_skipspace.c			\
			ft_strstr.c ft_lstdel.c ft_strcat.c ft_strsub.c					\
			ft_lstdel_content.c ft_strchr.c ft_strtrim.c ft_lstdelone.c		\
			ft_strclr.c ft_tolower.c ft_lstiter.c ft_strcmp.c ft_toupper.c	\
			ft_lstmap.c ft_strcpy.c ft_lstnew.c ft_strdel.c ft_sqrt.c		\
			ft_w_count.c ft_free_array.c ft_pow.c ft_atoi_base.c ft_abs.c	\
			ft_ltoa.c ft_lltoa.c ft_labs.c ft_utoa.c ft_ultoa.c ft_ulltoa.c	\
			ft_itoa_base.c ft_lltoa_base.c ft_ulltoa_base.c					\
			ft_atollu_base.c get_next_line.c 

OBJ		=	$(SRC:.c=.o)

SRCS	=	$(addprefix $(SRC_DIR), $(SRC))
OBJS	=	$(addprefix $(OBJ_DIR), $(OBJ))
INCS	=	$(addprefix $(INC_DIR), $(INC))

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	@gcc -c -I $(INC_DIR) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
