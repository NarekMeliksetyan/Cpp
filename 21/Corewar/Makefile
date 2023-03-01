# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 14:53:27 by dphyliss          #+#    #+#              #
#    Updated: 2021/01/13 16:31:34 by dphyliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

SRC_DIR = source/

ASM = asm

SRC_ASM = $(addprefix $(SRC_DIR),\
		main_asm.c\
		list_of_words.c\
		list_of_labels.c\
		parsing_lines.c\
		op.c\
		check_all.c\
		error_managment.c\
		convert_and_write.c\
		free_all.c\
		process_instruction.c\
		process_labels.c\
		cut_functions.c\
		process_args.c\
		write_args.c\
		help_functions.c\
		determine.c\
		disassembler.c\
		get_args_asm.c\
		read_and_parse.c)

OBJ_ASM = $(SRC_ASM:.c=.o)

COREWAR = corewar

SRC_COREWAR = $(addprefix $(SRC_DIR),\
		main.c\
		oper_st_fork.c\
		oper_live_ld.c\
		oper_func.c\
		oper_math.c\
		check_par.c\
		parse_champ.c\
		carriage.c\
		output.c\
		curses.c\
		imaging.c\
		oper_args.c\
		cycles.c\
		start_car.c\
		check.c\
		system.c\
		parse_cham.c)

OBJ_COREWAR = $(SRC_COREWAR:.c=.o)

LIB = libft/libft.a

CC = gcc

# remember debug flag 
CFLAGS = -Wall -Werror -Wextra -g

HEADER_OP = includes/op.h

HEADER_ASM = includes/asm.h

HEADER_COREWAR = includes/vm.h

all: $(LIB) $(ASM) $(COREWAR)

$(LIB):
	make -C libft/

$(ASM): $(OBJ_ASM) $(LIB)
	$(CC) $^ -o $@

$(OBJ_ASM): $(HEADER_OP) $(HEADER_ASM)

$(COREWAR): $(OBJ_COREWAR) $(LIB)
	$(CC) $^ -o $@ -lncurses

$(OBJ_COREWAR): $(HEADER_OP) $(HEADER_COREWAR)

clean:
	make clean -C libft
	rm -rf source/*.o

fclean: clean
	rm -rf $(ASM) $(COREWAR) $(LIB)

re: fclean all
