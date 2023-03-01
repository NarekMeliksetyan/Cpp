# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 16:32:57 by jkrypto           #+#    #+#              #
#    Updated: 2019/12/14 20:11:28 by jkrypto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	libft/libft.a

PS_NAME	=	push_swap
CH_NAME	=	checker
HD_NAME	=	push_swap.h

INC_DIR	=	./inc/
LIB_DIR	=	./libft/inc/
SRC_DIR	=	./src/
OBJ_DIR	=	./obj/

PS_SRC	=	commands_utils.c	\
			sort.c				\
			stack.c				\
			stack_push.c		\
			valid.c				\
			commands.c			\
			sort_utils.c		\
			stack_pop.c			\
			utils.c				\
			visual.c			\
			push_swap.c

CH_SRC	=	commands_utils.c	\
			sort.c				\
			stack.c				\
			stack_push.c		\
			valid.c				\
			commands.c			\
			sort_utils.c		\
			stack_pop.c			\
			utils.c				\
			visual.c			\
			checker.c

HEADER	=	$(addprefix $(INC_DIR), $(HD_NAME))
PS_OBJ	=	$(addprefix $(OBJ_DIR), $(PS_SRC:.c=.o))
CH_OBJ	=	$(addprefix $(OBJ_DIR), $(CH_SRC:.c=.o))

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
CC_LIB	=	-L ./libft -l ft

all: $(PS_NAME) $(CH_NAME)
	@echo "\033[32m~~~COMPILED~~~\033[0m"

$(PS_NAME): $(OBJ_DIR) $(PS_OBJ) $(LIBFT) $(HEADER)
	$(CC) $(CC_LIB) $(addprefix -I, $(INC_DIR)) $(PS_OBJ) $(FLAGS) -o $(PS_NAME)

$(CH_NAME): $(OBJ_DIR) $(CH_OBJ) $(LIBFT) $(HEADER)
	$(CC) $(CC_LIB) $(addprefix -I, $(INC_DIR)) $(CH_OBJ) $(FLAGS) -o $(CH_NAME)

$(OBJ_DIR):
	@mkdir -p obj

$(LIBFT):
	make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@$(CC) -c -I $(INC_DIR) -I $(LIB_DIR) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(PS_NAME) $(CH_NAME)
	@make fclean -C libft/
	@echo "\033[36m~~~CLEANED~~~\033[0m"

re: fclean all

.PHONY: all clean fclean re debug test
