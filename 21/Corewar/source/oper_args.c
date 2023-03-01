/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:04:28 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/17 15:55:48 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		define_type(int type)
{
	if (type == REG_CODE)
		return (T_REG);
	else if (type == DIR_CODE)
		return (T_DIR);
	else if (type == IND_CODE)
		return (T_IND);
	else
		return (0b111);
}

int		get_bytes(int start, int count, t_cell *map[])
{
	int temp;
	int i;

	temp = 0;
	i = -1;
	while (++i < count)
	{
		if (i != 0)
			temp <<= 8;
		temp |= map[(start + i) % MEM_SIZE]->value;
	}
	if (count == 2)
		return ((short)temp);
	else
		return (temp);
}

int		define_size(int code, int label)
{
	if (code == T_REG)
		return (1);
	else if (code == T_DIR)
	{
		if (label == false)
			return (4);
		else
			return (2);
	}
	else if (code == T_IND)
		return (2);
	else
		return (0);
}

int		vm_get_args(t_car *car, t_vm *vm)
{
	if (car->op->codage == true)
	{
		car->codage = vm->map[(car->position + 1) % MEM_SIZE]->value;
		car->type[1] = define_type(car->codage >> 6);
		car->type[2] = define_type(car->codage >> 4 & 0b0011);
		car->type[3] = define_type(car->codage >> 2 & 0b000011);
	}
	else
	{
		car->type[1] = define_type(car->op->args_type[0]);
		car->type[2] = define_type(car->op->args_type[1]);
		car->type[3] = define_type(car->op->args_type[2]);
	}
	car->size[1] = define_size(car->type[1], car->op->label);
	car->size[2] = car->op->args > 1 ?
		define_size(car->type[2], car->op->label) : 0;
	car->size[3] = car->op->args > 2 ?
		define_size(car->type[3], car->op->label) : 0;
	car->param[1].integer = get_bytes(car->position + car->op->codage + 1,
	car->size[1], vm->map);
	car->param[2].integer = get_bytes(car->position + car->op->codage + 1 +
	car->size[1], car->size[2], vm->map);
	car->param[3].integer = get_bytes(car->position + car->op->codage + 1 +
	car->size[1] + car->size[2], car->size[3], vm->map);
	return (car->op->codage + 1 + car->size[1] + car->size[2] + car->size[3]);
}
