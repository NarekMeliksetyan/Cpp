/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:05:51 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:45:24 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_bool		valid_reg(int reg)
{
	if (reg < 1 || reg > 16)
		return (false);
	else
		return (true);
}

void		throw_on_map(t_conv param, t_vm *vm, t_car *car, int i)
{
	int		j;

	i %= MEM_SIZE;
	if (i < 0)
		i += MEM_SIZE;
	vm->map[(i + 0) % MEM_SIZE]->value = param.bytes[3];
	vm->map[(i + 1) % MEM_SIZE]->value = param.bytes[2];
	vm->map[(i + 2) % MEM_SIZE]->value = param.bytes[1];
	vm->map[(i + 3) % MEM_SIZE]->value = param.bytes[0];
	j = -1;
	while (++j < 4)
	{
		vm->map[(i + j) % MEM_SIZE]->cycles_bold = vm->cycle;
		vm->map[(i + j) % MEM_SIZE]->color = car->creator->number;
	}
}

void		cw_aff(t_car *car, t_vm *vm)
{
	if (get_value(car, 1, vm, 0))
	{
		if (verbose_mode(vm))
			ft_printf("Aff: %c\n", (char)car->value[1]);
	}
}

t_conv		get_from_map(t_vm *vm, int i)
{
	t_conv	reg;

	i %= MEM_SIZE;
	if (i < 0)
		i += MEM_SIZE;
	reg.bytes[3] = vm->map[(i + 0) % MEM_SIZE]->value;
	reg.bytes[2] = vm->map[(i + 1) % MEM_SIZE]->value;
	reg.bytes[1] = vm->map[(i + 2) % MEM_SIZE]->value;
	reg.bytes[0] = vm->map[(i + 3) % MEM_SIZE]->value;
	return (reg);
}

t_bool		get_value(t_car *car, int num, t_vm *vm, int i)
{
	int		reg;
	t_conv	param;

	if (car->type[num] == T_DIR)
		car->value[num] = car->param[num].integer;
	else if (car->type[num] == T_REG)
	{
		if (!valid_reg(reg = car->param[num].integer))
			return (false);
		else
			car->value[num] = car->reg[reg].integer;
	}
	else if (car->type[num] == T_IND)
	{
		i %= MEM_SIZE;
		if (i < 0)
			i += MEM_SIZE;
		param.bytes[3] = vm->map[(i + 0) % MEM_SIZE]->value;
		param.bytes[2] = vm->map[(i + 1) % MEM_SIZE]->value;
		param.bytes[1] = vm->map[(i + 2) % MEM_SIZE]->value;
		param.bytes[0] = vm->map[(i + 3) % MEM_SIZE]->value;
		car->value[num] = param.integer;
	}
	return (true);
}
