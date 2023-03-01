/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:05:45 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:39:12 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	cw_or(t_car *car, t_vm *vm)
{
	int reg;

	if (get_value(car, 1, vm,
	car->position + car->param[1].integer % IDX_MOD) &&
	get_value(car, 2, vm,
	car->position + car->param[2].integer % IDX_MOD) &&
	valid_reg(reg = car->param[3].integer))
	{
		car->reg[reg].integer = car->value[1] | car->value[2];
		car->carry = car->reg[reg].integer == 0 ? true : false;
		if (verbose_mode(vm))
			ft_printf("P %4d | or %d %d r%d\n",
			car->number, car->value[1], car->value[2], reg);
	}
}

void	cw_xor(t_car *car, t_vm *vm)
{
	int reg;

	if (get_value(car, 1, vm,
	car->position + car->param[1].integer % IDX_MOD) &&
	get_value(car, 2, vm,
	car->position + car->param[2].integer % IDX_MOD) &&
	valid_reg(reg = car->param[3].integer))
	{
		car->reg[reg].integer = car->value[1] ^ car->value[2];
		car->carry = car->reg[reg].integer == 0 ? true : false;
		if (verbose_mode(vm))
			ft_printf("P %4d | xor %d %d r%d\n",
			car->number, car->value[1], car->value[2], reg);
	}
}

void	cw_add(t_car *car, t_vm *vm)
{
	int reg1;
	int reg2;
	int reg3;

	if (valid_reg(reg1 = car->param[1].integer) &&
			valid_reg(reg2 = car->param[2].integer) &&
					valid_reg(reg3 = car->param[3].integer))
	{
		car->reg[reg3].integer = car->reg[reg1].integer +
												car->reg[reg2].integer;
		car->carry = car->reg[reg3].integer == 0 ? true : false;
		if (verbose_mode(vm))
			ft_printf("P %4d | add r%d r%d r%d\n",
										car->number, reg1, reg2, reg3);
	}
}

void	cw_and(t_car *car, t_vm *vm)
{
	int reg;

	if (get_value(car, 1, vm,
	car->position + car->param[1].integer % IDX_MOD) &&
	get_value(car, 2, vm,
	car->position + car->param[2].integer % IDX_MOD) &&
	valid_reg(reg = car->param[3].integer))
	{
		car->reg[reg].integer = car->value[1] & car->value[2];
		car->carry = car->reg[reg].integer == 0 ? true : false;
		if (verbose_mode(vm))
			ft_printf("P %4d | and %d %d r%d\n",
			car->number, car->value[1], car->value[2], reg);
	}
}

void	cw_sub(t_car *car, t_vm *vm)
{
	int reg1;
	int reg2;
	int reg3;

	if (valid_reg(reg1 = car->param[1].integer) &&
			valid_reg(reg2 = car->param[2].integer) &&
					valid_reg(reg3 = car->param[3].integer))
	{
		car->reg[reg3].integer = car->reg[reg1].integer -
												car->reg[reg2].integer;
		car->carry = car->reg[reg3].integer == 0 ? true : false;
		if (verbose_mode(vm))
			ft_printf("P %4d | sub r%d r%d r%d\n",
										car->number, reg1, reg2, reg3);
	}
}
