# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 18:30:08 by jkrypto           #+#    #+#              #
#    Updated: 2019/09/18 17:27:26 by jkrypto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC	=	ft_abs.c				ft_atoi.c				ft_atoi_base.c		\
		ft_bzero.c				ft_dup.c				ft_factorial.c		\
		ft_find_next_prime.c	ft_foreach.c			ft_isalnum.c		\
		ft_isalpha.c			ft_isascii.c			ft_isdigit.c		\
		ft_islower.c			ft_isprime.c			ft_isprint.c		\
		ft_isupper.c			ft_itoa.c				ft_itoa_base.c		\
		ft_lstadd.c				ft_lstaddend.c			ft_lstdel.c			\
		ft_lstdelone.c			ft_lstiter.c			ft_lstmap.c			\
		ft_lstnew.c				ft_lstsize.c			ft_lstsort.c		\
		ft_memalloc.c			ft_memccpy.c			ft_memchr.c			\
		ft_memcmp.c				ft_memcpy.c				ft_memdel.c			\
		ft_memmove.c			ft_memset.c				ft_power.c			\
		ft_putchar.c			ft_putchar_fd.c			ft_putendl.c		\
		ft_putendl_fd.c			ft_putnbr.c				ft_putnbr_fd.c		\
		ft_putstr.c				ft_putstr_fd.c			ft_sqrt.c			\
		ft_strcapitalize.c		ft_strcat.c				ft_strchr.c			\
		ft_strclr.c				ft_strcmp.c				ft_strcpy.c			\
		ft_strdel.c				ft_strdup.c				ft_strequ.c			\
		ft_striter.c			ft_striteri.c			ft_strjoin.c		\
		ft_strlcat.c			ft_strlen.c				ft_strmap.c			\
		ft_strmapi.c			ft_strncat.c			ft_strncmp.c		\
		ft_strncpy.c			ft_strnequ.c			ft_strnew.c			\
		ft_strnstr.c			ft_strrchr.c			ft_strrev.c			\
		ft_strsplit.c			ft_strstr.c				ft_strsub.c			\
		ft_sort_bubble.c		ft_sort_quick.c			ft_sort_select.c	\
		ft_strtrim.c			ft_swap.c				ft_tolower.c		\
		ft_toupper.c

OBJ		= $(SRC:.c=.o)	
INC		= -I includes
FLAGS	= -Wall -Wextra -Werror

SRCDIR	= srcs/
OBJDIR	= objs/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))

.PHONY:		all clean fclean re check
.SUFFIXES:	.c .o

all: $(NAME)

$(OBJS): $(SRCS)
	@/bin/mkdir -p $(OBJDIR) ;
	@gcc -c $(FLAGS) $(SRCS) $(INC) ;
	@/bin/mv $(OBJ) $(OBJDIR)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

check: all fclean
