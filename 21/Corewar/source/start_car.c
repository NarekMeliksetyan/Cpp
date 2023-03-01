/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_car.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:06:44 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:42:47 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_bool	args_ok(t_car *car)
{
	if (car->size[1] == 0 ||
		(car->op->args_type[0] | car->type[1]) != car->op->args_type[0])
		return (false);
	if (car->op->args > 1 && (car->size[2] == 0 ||
		(car->op->args_type[1] | car->type[2]) != car->op->args_type[1]))
		return (false);
	if (car->op->args > 2 && (car->size[3] == 0 ||
		(car->op->args_type[2] | car->type[3]) != car->op->args_type[2]))
		return (false);
	return (true);
}

void	get_command(t_vm *vm, t_car *car)
{
	int		i;

	if (car->op == NULL)
	{
		i = -1;
		while (g_op_tab[++i].name)
		{
			if (g_op_tab[i].code == vm->map[car->position]->value)
				car->op = &g_op_tab[i];
		}
		if (car->op)
			car->cooldown = car->op->cooldown;
		else
			car->position = (car->position + 1) % MEM_SIZE;
	}
}

void	run_cars(t_vm *vm)
{
	t_car	*car;
	int		diff;

	car = vm->cars;
	while (car)
	{
		get_command(vm, car);
		if (car->op && --car->cooldown == 0)
		{
			diff = vm_get_args(car, vm);
			if (args_ok(car))
				car->op->func(car, vm);
			if (car->carry == false || car->op->code != 0x09)
			{
				adv(vm, diff, car);
				car->position = (car->position + diff) % MEM_SIZE;
			}
			car->op = NULL;
		}
		car = car->next;
	}
}
