/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:04:01 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:04:03 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	check_code(t_asm *asm_parsing, unsigned char *all_code,
										unsigned char codage, int instruction)
{
	instruction = parse_bytecode(asm_parsing, all_code, 1);
	if (instruction > 16)
		error_dis("Unknown instruction");
	if (g_op_tab[instruction - 1].codage_octal == 1)
	{
		codage = parse_bytecode(asm_parsing, all_code, 1);
		ft_printf("%s ", g_op_tab[instruction - 1].name);
		get_args_codage(asm_parsing, all_code, instruction, codage);
	}
	else
	{
		ft_printf("%s ", g_op_tab[instruction - 1].name);
		get_args(asm_parsing, all_code, instruction);
	}
}

static void	read_code(t_asm *asm_parsing, int size_code)
{
	unsigned char	*all_code;
	int				instruction;
	int				ret;
	unsigned char	codage;

	instruction = 0;
	codage = '\0';
	all_code = (unsigned char *)malloc(sizeof(char) * size_code);
	ret = read(asm_parsing->fd, all_code, size_code);
	if (ret != size_code)
		error_dis("File has a code size that differ from what its header says");
	ret = 0;
	while (asm_parsing->position != size_code)
		check_code(asm_parsing, all_code, codage, instruction);
	ret = read(asm_parsing->fd, all_code, 1);
	if (ret == 1)
		error_dis("File has a code size that differ from what its header says");
	free(all_code);
}

static void	print_result(t_asm *asm_parsing)
{
	g_fd = 1;
	ft_printf("Writing to file %s\n", asm_parsing->filename);
	ft_strdel(&asm_parsing->filename);
}

static void	file_rename(t_asm *asm_parsing, const char *filename)
{
	char *file_to_write;

	filename = ft_strsub(filename, 0, ft_strlen(filename) - 4);
	file_to_write = ft_strjoin(filename, ".s");
	asm_parsing->fd_dis = open(file_to_write,
								O_CREAT | O_WRONLY | O_TRUNC, 0644);
	g_fd = asm_parsing->fd_dis;
	ft_strdel(&asm_parsing->filename);
	asm_parsing->filename = file_to_write;
	free((char *)filename);
}

void		disassembler(const char *filename)
{
	t_asm	*asm_parsing;
	int		ret;
	int		size_code;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_arg_error("Can't open this file");
	asm_parsing = init_asm(fd, filename);
	file_rename(asm_parsing, filename);
	ret = help_dis(asm_parsing, 4);
	if (ret != COREWAR_EXEC_MAGIC)
		error_dis("MAGIC is wrong");
	read_name(asm_parsing);
	ret = help_dis(asm_parsing, 4);
	if (ret != 0)
		error_dis("NULL is wrong");
	size_code = help_dis(asm_parsing, 4);
	asm_parsing->size_code = size_code;
	read_comment(asm_parsing);
	ret = help_dis(asm_parsing, 4);
	if (ret != 0)
		error_dis("NULL is wrong");
	read_code(asm_parsing, size_code);
	print_result(asm_parsing);
	free(asm_parsing);
}
