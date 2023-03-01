/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:03:20 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:33:30 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		verbose_mode(t_vm *vm)
{
	if (vm->flag_verbose && vm->cycle >= vm->flag_dump)
		return (1);
	else
		return (0);
}

void	remove_start(t_car **cars, t_vm *vm)
{
	t_car *del;

	while (*cars && (vm->cycle - (*cars)->last_live >= vm->cycles_to_die ||
	vm->cycles_to_die <= 0))
	{
		if (verbose_mode(vm))
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				(*cars)->number, vm->cycle - (*cars)->last_live,
				vm->cycles_to_die);
		del = *cars;
		*cars = (*cars)->next;
		free(del);
	}
}

void	delete_cars(t_car **cars, t_vm *vm)
{
	t_car *del;
	t_car *tmp;

	remove_start(cars, vm);
	tmp = *cars;
	while (tmp && tmp->next)
	{
		if (vm->cycle - tmp->next->last_live >= vm->cycles_to_die ||
													vm->cycles_to_die <= 0)
		{
			if (verbose_mode(vm))
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					tmp->next->number, vm->cycle - tmp->next->last_live,
														vm->cycles_to_die);
			del = tmp->next;
			tmp->next = tmp->next->next;
			free(del);
		}
		else
			tmp = tmp->next;
	}
}

void	cw_check(t_vm *vm)
{
	vm->cycles_after_check += 1;
	if (vm->cycles_after_check >= vm->cycles_to_die)
	{
		vm->checks += 1;
		delete_cars(&vm->cars, vm);
		if (vm->all_lives >= NBR_LIVE || vm->checks == MAX_CHECKS)
		{
			vm->cycles_to_die -= CYCLE_DELTA;
			vm->checks = 0;
			if (verbose_mode(vm))
				ft_printf("Cycle to die is now %d\n", vm->cycles_to_die);
		}
		vm->cycles_after_check = 0;
		vm->champs[0]->lives_cur_period = 0;
		vm->all_lives = 0;
	}
}
