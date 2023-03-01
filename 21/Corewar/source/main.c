/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:05:20 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/17 12:39:30 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_vm			*init(void)
{
	t_vm		*vm;
	int			i;

	i = -1;
	if (!(vm = ft_memalloc(sizeof(t_vm))))
		ft_error_exit(ERROR_MEMORY_ALLOCATED);
	while (++i < MEM_SIZE)
	{
		if (!(vm->map[i] = ft_memalloc(sizeof(t_cell))))
			ft_error_exit(ERROR_MEMORY_ALLOCATED);
		vm->map[i]->value = 0x00;
	}
	vm->cars = NULL;
	vm->flag_dump = -1;
	vm->cycles_to_die = CYCLE_TO_DIE;
	g_fd = 1;
	vm->flag_run = false;
	vm->cycles_in_second = 50;
	return (vm);
}

int				main(int ac, char **av)
{
	t_vm		*vm;

	parse_par(ac, av, vm = init());
	parse_champs(vm);
	throw_basic_cars(vm);
	load(vm, vm->champs, vm->flag_visual);
	init_curses(vm);
	if (vm->flag_dump == 0)
		dump(vm);
	while (true)
		if (iteration(vm))
		{
			run_cars(vm);
			cw_check(vm);
			if (!vm->cars)
			{
				verbose_win(vm);
				break ;
			}
			if (vm->cycle == vm->flag_dump)
				dump(vm);
		}
	over_curses(vm);
	cleen_all(vm);
	return (0);
}
