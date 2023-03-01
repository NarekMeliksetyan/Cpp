/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:59:43 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:53:02 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libft/includes/libft.h"
# include "op.h"
# include <curses.h>
# include <fcntl.h>
# include <time.h>

/*
**	Error managment
*/

# define ERROR_GIGA_CHAMP 		"The big сhampion"
# define ERROR_N_EXCEEDS 		"The number of champions exceeds their number"
# define ERROR_FILE_EXTENTION 	"Incorrect champion file extension"
# define ERROR_DUMP_NUMBER 		"-dump needs a valid number"
# define ERROR_HEADER 			"Incorrect magic header"
# define ERROR_GIGA_CHAMPS 		"A maximum of 4 champions"
# define ERROR_NULL_CHAMPS 		"Champions are not represented"
# define ERROR_COMMENT_NULL 	"No empty octets after the comment"
# define ERROR_NAME_NULL 		"No empty octets after the name"
# define ERROR_CHAMP 			"Invalid flag -n"
# define ERROR_RANGE 			"Invalid range for -n flag"
# define ERROR_OPEN 			"Error when opening"
# define ERROR_DUPLICAT 		"Duplication of champion's number"
# define ERROR_CODE_SIZE 		"File has incorrect size of code"
# define ERROR_FILE_CHAMP		"Too small a file for a champion"
# define ERROR_FLAG_COMBINATION	"Incorrect combination of flags"
# define ERROR_MEMORY_ALLOCATED	"The system did`t allocate memory"

/*
**	Visualization control buttons
*/

# define KEY_E 		101
# define KEY_ESC 	27
# define KEY_S 		115
# define KEY_SPACE 	32
# define KEY_W 		119

typedef struct		s_champ
{
	char			*file;
	int				last_live;
	int				lives_cur_period;
	int				number;
	t_header		*header;
}					t_champ;

typedef struct		s_cell
{
	unsigned char	value;
	int				color;
	int				cycles_bold;
	int				cycles_live;
}					t_cell;

typedef union		u_conv
{
	int				integer;
	unsigned char	bytes[REG_SIZE];
}					t_conv;

typedef struct		s_car
{
	int				codage;
	int				cooldown;
	int				last_live;
	int				number;
	int				position;
	int				size[MAX_ARGS_NUMBER];
	int				type[MAX_ARGS_NUMBER];
	int				value[MAX_ARGS_NUMBER];
	t_bool			carry:1;
	t_champ			*creator;
	t_conv			param[MAX_ARGS_NUMBER];
	t_conv			reg[REG_NUMBER + 1];
	struct s_op		*op;
	struct s_car	*next;
}					t_car;

typedef struct		s_vm
{
	int				all_lives;
	int				checks;
	int				count_champ;
	int				cycle;
	int				cycles_after_check;
	int				cycles_in_second;
	int				cycles_to_die;
	int				flag_dump;
	int				last_line;
	int				last_print;
	int				proc_count;
	int				procs_count;
	t_bool			flag_run:1;
	t_bool			flag_verbose:1;
	t_bool			flag_visual:1;
	t_car			*cars;
	t_cell			*map[MEM_SIZE];
	t_champ			*champs[MAX_PLAYERS + 1];
	t_champ			*last_live;
	WINDOW			*win_info;
	WINDOW			*win_mem;
	float			time;
}					t_vm;

typedef struct		s_op
{
	char			*name;
	int				args;
	int				args_type[3];
	int				code;
	int				cooldown;
	t_bool			codage:1;
	t_bool			label:1;
	void			(*func)(t_car *, t_vm *);
}					t_op;

/*
**	Virtual machine
*/

int					verbose_mode(t_vm *vm);
void				delete_cars(t_car **list, t_vm *vm);
void				cleen_all(t_vm *vm);
void				ft_error_exit(char *message);
void				parse_par(int argc, char **argv, t_vm *vm);
void				parse_champs(t_vm *vm);
t_bool				is_champ(char *name);
t_champ				*new_champ(char *file);
void				push_car(t_car *car, t_car **list);
t_car				*new_car(t_vm *vm, t_champ *creator);
void				throw_basic_cars(t_vm *vm);
void				verbose_win(t_vm *vm);
void				load(t_vm *war, t_champ **champs, t_bool flag_visual);
t_bool				get_value(t_car *car, int num, t_vm *vm, int index);
t_bool				valid_reg(int reg_num);
t_conv				get_from_map(t_vm *vm, int index);
void				throw_on_map(t_conv value, t_vm *vm,
									t_car *car, int index);
void				run_cars(t_vm *vm);
void				cw_check(t_vm *vm);
void				vm_read_com(int fd, char *comment);
int					vm_code_size(int fd);
int					vm_parse_null(int fd);
void				vm_parse_name(int fd, char *name);
int					vm_get_args(t_car *car, t_vm *vm);
int					parse_magic_header(int fd);
t_bool				iteration(t_vm *vm);
void				dump(t_vm *vm);
void				adv(t_vm *vm, int instr_len, t_car *car);
t_champ				*find_champ(int number, t_vm *vm);
void				usage(void);

/*
**	Operation
*/

void				cw_add(t_car *car, t_vm *vm);
void				cw_aff(t_car *car, t_vm *vm);
void				cw_and(t_car *car, t_vm *vm);
void				cw_fork(t_car *car, t_vm *vm);
void				cw_ld(t_car *car, t_vm *vm);
void				cw_ldi(t_car *car, t_vm *vm);
void				cw_lfork(t_car *car, t_vm *vm);
void				cw_live(t_car *car, t_vm *vm);
void				cw_lld(t_car *car, t_vm *vm);
void				cw_lldi(t_car *car, t_vm *vm);
void				cw_or(t_car *car, t_vm *vm);
void				cw_st(t_car *car, t_vm *vm);
void				cw_sti(t_car *car, t_vm *vm);
void				cw_sub(t_car *car, t_vm *vm);
void				cw_xor(t_car *car, t_vm *vm);
void				cw_zjmp(t_car *car, t_vm *vm);

/*
**	Vizualization
*/

void				print_info(t_vm *vm);
void				print_memory(t_vm *vm);
void				init_curses(t_vm *vm);
void				over_over(t_vm *vm);
void				over_curses(t_vm *vm);

static t_op		g_op_tab[] =
{
	{
		.name = "live",
		.args = 1,
		.args_type = {T_DIR, 0, 0},
		.code = 0x01,
		.cooldown = 10,
		.codage = false,
		.label = false,
		.func = &cw_live
	},
	{
		.name = "ld",
		.args = 2,
		.args_type = {T_DIR | T_IND, T_REG, 0},
		.code = 0x02,
		.cooldown = 5,
		.codage = true,
		.label = false,
		.func = &cw_ld
	},
	{
		.name = "st",
		.args = 2,
		.args_type = {T_REG, T_IND | T_REG, 0},
		.code = 0x03,
		.cooldown = 5,
		.codage = true,
		.label = false,
		.func = &cw_st
	},
	{
		.name = "add",
		.args = 3,
		.args_type = {T_REG, T_REG, T_REG},
		.code = 0x04,
		.cooldown = 10,
		.codage = true,
		.label = false,
		.func = &cw_add
	},
	{
		.name = "sub",
		.args = 3,
		.args_type = {T_REG, T_REG, T_REG},
		.code = 0x05,
		.cooldown = 10,
		.codage = true,
		.label = false,
		.func = &cw_sub
	},
	{
		.name = "and",
		.args = 3,
		.args_type = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.code = 0x06,
		.cooldown = 6,
		.codage = true,
		.label = false,
		.func = &cw_and
	},
	{
		.name = "or",
		.args = 3,
		.args_type = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.code = 0x07,
		.cooldown = 6,
		.codage = true,
		.label = false,
		.func = &cw_or
	},
	{
		.name = "xor",
		.args = 3,
		.args_type = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.code = 0x08,
		.cooldown = 6,
		.codage = true,
		.label = false,
		.func = &cw_xor
	},
	{
		.name = "zjmp",
		.args = 1,
		.args_type = {T_DIR, 0, 0},
		.code = 0x09,
		.cooldown = 20,
		.codage = false,
		.label = true,
		.func = &cw_zjmp
	},
	{
		.name = "ldi",
		.args = 3,
		.args_type = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.code = 0x0a,
		.cooldown = 25,
		.codage = true,
		.label = true,
		.func = &cw_ldi
	},
	{
		.name = "sti",
		.args = 3,
		.args_type = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		.code = 0x0b,
		.cooldown = 25,
		.codage = true,
		.label = true,
		.func = &cw_sti
	},
	{
		.name = "fork",
		.args = 1,
		.args_type = {T_DIR, 0, 0},
		.code = 0x0c,
		.cooldown = 800,
		.codage = false,
		.label = true,
		.func = &cw_fork
	},
	{
		.name = "lld",
		.args = 2,
		.args_type = {T_DIR | T_IND, T_REG, 0},
		.code = 0x0d,
		.cooldown = 10,
		.codage = true,
		.label = false,
		.func = &cw_lld
	},
	{
		.name = "lldi",
		.args = 3,
		.args_type = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.code = 0x0e,
		.cooldown = 50,
		.codage = true,
		.label = true,
		.func = &cw_lldi
	},
	{
		.name = "lfork",
		.args = 1,
		.args_type = {T_DIR, 0, 0},
		.code = 0x0f,
		.cooldown = 1000,
		.codage = false,
		.label = true,
		.func = &cw_lfork
	},
	{
		.name = "aff",
		.args = 1,
		.args_type = {T_REG, 0, 0},
		.code = 0x10,
		.cooldown = 2,
		.codage = true,
		.label = false,
		.func = &cw_aff
	},
	{
		.name = NULL,
		.args = 0,
		.args_type = {0, 0, 0},
		.code = 0,
		.cooldown = 0,
		.codage = 0,
		.label = 0,
		.func = 0
	}
};

#endif
