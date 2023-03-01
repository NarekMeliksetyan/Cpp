/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_st_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:05:34 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:46:06 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	cw_fork(t_car *car, t_vm *vm)
{
	int		i;
	t_car	*child;

	child = new_car(vm, car->creator);
	child->position = car->position + car->param[1].integer % IDX_MOD;
	while (child->position < 0)
		child->position += MEM_SIZE;
	child->position %= MEM_SIZE;
	push_car(child, &vm->cars);
	i = -1;
	while (++i <= REG_NUMBER)
		child->reg[i] = car->reg[i];
	child->last_live = car->last_live;
	child->carry = car->carry;
	if (verbose_mode(vm))
		ft_printf("P %4d | fork %d (%d)\n", car->number,
		car->param[1].integer, car->position +
									car->param[1].integer % IDX_MOD);
}

void	cw_zjmp(t_car *car, t_vm *vm)
{
	char	*status;

	if (car->carry == true)
	{
		car->position = (car->position + (car->param[1].integer % IDX_MOD))
																% MEM_SIZE;
		if (car->position < 0)
			car->position += MEM_SIZE;
		status = "OK";
	}
	else
		status = "FAILED";
	if (verbose_mode(vm))
		ft_printf("P %4d | zjmp %d %s\n", car->number,
		car->param[1].integer, status);
}

void	cw_lfork(t_car *car, t_vm *vm)
{
	t_car	*child;
	int		i;

	child = new_car(vm, car->creator);
	child->position = car->position + car->param[1].integer;
	while (child->position < 0)
		child->position += MEM_SIZE;
	child->position %= MEM_SIZE;
	push_car(child, &vm->cars);
	i = -1;
	while (++i <= REG_NUMBER)
		child->reg[i] = car->reg[i];
	child->last_live = car->last_live;
	child->carry = car->carry;
	if (verbose_mode(vm))
	{
		ft_printf("P %4d | lfork %d (%d)\n", car->number,
			car->param[1].integer, car->position + car->param[1].integer);
	}
}

void	cw_st(t_car *car, t_vm *vm)
{
	int		reg1;
	int		reg2;

	if (valid_reg(reg1 = car->param[1].integer))
	{
		if (car->type[2] == T_IND)
			throw_on_map(car->reg[reg1], vm, car,
				car->position + car->param[2].integer % IDX_MOD);
		else if (car->type[2] == T_REG)
		{
			if (!valid_reg(reg2 = car->param[2].integer))
				return ;
			else
			{
				car->reg[reg2].bytes[0] = car->reg[reg1].bytes[0];
				car->reg[reg2].bytes[1] = car->reg[reg1].bytes[1];
				car->reg[reg2].bytes[2] = car->reg[reg1].bytes[2];
				car->reg[reg2].bytes[3] = car->reg[reg1].bytes[3];
			}
		}
		if (verbose_mode(vm))
			ft_printf("P %4d | st r%d %d\n",
			car->number, reg1, car->param[2].integer);
	}
}

void	cw_sti(t_car *car, t_vm *vm)
{
	int		reg1;
	int		i;

	if (get_value(car, 2, vm, car->position +
			car->param[2].integer % IDX_MOD) &&
				get_value(car, 3, vm, car->position +
					car->param[2].integer % IDX_MOD) &&
						valid_reg(reg1 = car->param[1].integer))
	{
		i = car->position + (car->value[2] + car->value[3]) % IDX_MOD;
		throw_on_map(car->reg[reg1], vm, car, i);
		if (verbose_mode(vm))
		{
			ft_printf("P %4d | sti r%d %d %d\n",
						car->number, reg1, car->value[2], car->value[3]);
			ft_printf("       | -> store to %d + %d = %d ",
				car->value[2], car->value[3], car->value[2] + car->value[3]);
			ft_printf("(with pc and mod %d)\n", index);
		}
	}
}
