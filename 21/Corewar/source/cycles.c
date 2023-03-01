/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:05:28 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:27:21 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_bool	cyc_inc_alowed(int button, t_vm *vm)
{
	t_bool suc;

	suc = false;
	if (!vm->flag_visual || button == KEY_S ||
	vm->cycle < vm->flag_dump || (vm->flag_run &&
	((float)clock() / CLOCKS_PER_SEC - vm->time >=
	1.0 / vm->cycles_in_second)))
	{
		vm->cycle += 1;
		suc = true;
		if (vm->flag_visual &&
		(!vm->flag_run ||
		vm->cycle - vm->last_print >= vm->cycles_in_second))
		{
			vm->time = (float)clock() / CLOCKS_PER_SEC;
			vm->last_print = vm->cycle;
		}
		vm->time += 1.0 / vm->cycles_in_second;
	}
	return (suc);
}

void	handle_key(int button, t_vm *vm)
{
	if (button == KEY_ESC)
		over_over(vm);
	if (button == KEY_W)
	{
		if (vm->cycles_in_second > 1)
			vm->cycles_in_second -= 1;
	}
	if (button == KEY_E)
		vm->cycles_in_second += 1;
	if (button == KEY_SPACE)
		vm->flag_run = (vm->flag_run == true) ? false : true;
}

t_bool	iteration(t_vm *vm)
{
	int		button;
	t_bool	suc;

	button = 0;
	if (vm->flag_visual && vm->cycle >= vm->flag_dump)
	{
		handle_key(button = getch(), vm);
		print_info(vm);
	}
	suc = cyc_inc_alowed(button, vm);
	if (vm->flag_visual)
	{
		if (vm->cycle >= vm->flag_dump)
			print_memory(vm);
		print_info(vm);
	}
	if (verbose_mode(vm))
		ft_printf("It is now cycle %d\n", vm->cycle);
	return (suc);
}
