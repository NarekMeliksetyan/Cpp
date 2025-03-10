/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:06:15 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:06:18 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_for_digits(char *nbr)
{
	size_t i;

	i = 0;
	if (nbr[i] == '-')
		i++;
	while (i < ft_strlen(nbr))
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

void		process_direct_arg(t_codage *codage,
							t_instruction *instruction_args, t_word *current)
{
	codage->sum = T_DIR |
					g_op_tab[codage->instruction].type_args[codage->count_args];
	if (codage->sum !=
					g_op_tab[codage->instruction].type_args[codage->count_args])
		error_word2(current, "Incorrect argument");
	codage->var_for_codage = codage->var_for_codage |
								(DIR_CODE << codage->shift_left);
	codage->shift_left -= 2;
	instruction_args->args[codage->count_args] = current;
	codage->count_args++;
}

void		process_indirect_arg(t_codage *codage,
							t_instruction *instruction_args, t_word *current)
{
	codage->sum = T_IND |
					g_op_tab[codage->instruction].type_args[codage->count_args];
	if (codage->sum !=
					g_op_tab[codage->instruction].type_args[codage->count_args])
		error_word2(current, "Incorrect argument");
	codage->var_for_codage = codage->var_for_codage |
								(IND_CODE << codage->shift_left);
	codage->shift_left -= 2;
	instruction_args->args[codage->count_args] = current;
	codage->count_args++;
}

void		process_register_arg(t_codage *codage,
							t_instruction *instruction_args, t_word *current)
{
	codage->sum = T_REG |
					g_op_tab[codage->instruction].type_args[codage->count_args];
	if (codage->sum !=
					g_op_tab[codage->instruction].type_args[codage->count_args])
		error_word2(current, "Incorrect argument");
	codage->var_for_codage = codage->var_for_codage |
								(REG_CODE << codage->shift_left);
	codage->shift_left -= 2;
	instruction_args->args[codage->count_args] = current;
	codage->count_args++;
}

t_codage	*init_codage(void)
{
	t_codage	*codage;

	codage = (t_codage *)malloc(sizeof(t_codage));
	codage->instruction = 0;
	codage->count_args = 0;
	codage->sum = 0;
	codage->var_for_codage = 0;
	codage->shift_left = 6;
	return (codage);
}
