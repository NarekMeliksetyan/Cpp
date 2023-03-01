# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 16:32:57 by jkrypto           #+#    #+#              #
#    Updated: 2020/03/13 01:22:39 by tinkotsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	libft/libft.a

NAME	=	lem-in
HEAD	=	lemin.h

INC_DIR	=	./incs/
LIB_DIR	=	./libft/includes/
SRC_DIR	=	./srcs/
OBJ_DIR	=	./objs/

SRC		=	main.c			\
			check_sharp.c	\
			create_room.c	\
			links.c			\
			parse_map.c		\
			error.c			\
			hash_map.c		\
			bfs.c			\
			change_path.c	\
			bellman_ford.c	\
			suurballe.c		\
			solutions.c		\
			queue.c			\
			sols_mem.c		\
			save_file.c		\
			ants.c			\
			ants_mem.c		\
			free_all.c		\
			links_to_q.c

HEADER	=	$(addprefix $(INC_DIR), $(HEAD))
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

COMP_LIB = make -C libft/
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
CC_LIB	= -L ./libft -lft

all: lib $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(addprefix -I, $(INC_DIR)) $(OBJ) $(FLAGS) -o $(NAME) $(CC_LIB)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(COMP_LIB)

lib:
	$(COMP_LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -I $(INC_DIR) -I $(LIB_DIR) $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME) $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
