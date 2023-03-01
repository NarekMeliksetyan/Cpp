/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:02:00 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:33:13 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_car		*new_car(t_vm *vm, t_champ *champ)
{
	t_car	*car;
	int		position;

	position = MEM_SIZE / vm->count_champ;
	if (!(car = ft_memalloc(sizeof(t_car))))
		ft_error_exit(ERROR_MEMORY_ALLOCATED);
	car->position = position * (champ->number - 1);
	car->creator = champ;
	car->number = ++(vm->proc_count);
	vm->procs_count++;
	car->reg[1].integer = -(champ->number);
	car->carry = false;
	return (car);
}

void		push_car(t_car *car, t_car **cars)
{
	car->next = *cars;
	*cars = car;
}

void		throw_basic_cars(t_vm *vm)
{
	int		i;
	t_car	*car;

	i = -1;
	while (vm->champs[++i] != NULL)
	{
		car = new_car(vm, vm->champs[i]);
		push_car(car, &vm->cars);
	}
}
