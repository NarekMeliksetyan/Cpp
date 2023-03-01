# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 18:30:08 by jkrypto           #+#    #+#              #
#    Updated: 2019/11/13 12:21:37 by jkrypto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	*.c
OBJ		=	$(SRC:.c=.o)	

INC		=	-I includes
FLAGS	=	-Wall -Wextra -Werror

SRCDIR	=	srcs/
OBJDIR	=	objs/

SRCS	=	$(addprefix $(SRCDIR), $(SRC))
OBJS	=	$(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(OBJS): $(SRCS)
	/bin/mkdir -p $(OBJDIR) ;
	gcc -c $(FLAGS) $(SRCS) $(INC) ;
	/bin/mv $(OBJ) $(OBJDIR)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

check: all fclean

.PHONY:		all clean fclean re check
