/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_live_ld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:05:39 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:41:27 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	cw_ldi(t_car *car, t_vm *vm)
{
	int num;
	int i;

	if (get_value(car, 1, vm, car->position + car->param[1].integer) &&
	get_value(car, 2, vm, 0) &&
						valid_reg(num = car->param[3].integer))
	{
		i = car->position + (car->value[1] + car->value[2]) % IDX_MOD;
		car->reg[num] = get_from_map(vm, i);
		if (verbose_mode(vm))
		{
			ft_printf("P %4d | ldi %d %d r%d\n", car->number, car->value[1],
													car->value[2], num);
			ft_printf("       | -> load from %d + %d = %d ",
				car->value[1], car->value[2], car->value[1] + car->value[2]);
			ft_printf("(with pc and mod %d)\n", i);
		}
	}
}

void	cw_lldi(t_car *car, t_vm *vm)
{
	int num;
	int i;

	if (get_value(car, 1, vm, car->position + car->param[1].integer) &&
	get_value(car, 2, vm, 0) &&
						valid_reg(num = car->param[3].integer))
	{
		i = car->position + car->value[1] + car->value[2];
		car->reg[num] = get_from_map(vm, i);
		car->carry = car->reg[num].integer == 0 ? true : false;
		if (verbose_mode(vm))
		{
			ft_printf("P %4d | lldi %d %d r%d\n", car->number, car->value[1],
													car->value[2], num);
			ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
			car->value[1], car->value[2], car->value[1] + car->value[2], i);
		}
	}
}

void	cw_live(t_car *car, t_vm *vm)
{
	t_champ *champ;

	car->last_live = vm->cycle;
	vm->map[car->position]->cycles_live = vm->cycle;
	champ = find_champ(car->param[1].integer, vm);
	if (champ != NULL)
	{
		champ->last_live = vm->cycle;
		(champ->lives_cur_period)++;
		vm->last_live = champ;
	}
	vm->all_lives += 1;
	if (verbose_mode(vm))
	{
		ft_printf("P %4d | live %d\n", car->number, car->param[1].integer);
		if (champ != NULL)
		{
			ft_printf("Player %d (%s) is said to be alive\n",
				champ->number, champ->header->prog_name);
		}
	}
}

void	cw_lld(t_car *car, t_vm *vm)
{
	int num;

	if (valid_reg(num = car->param[2].integer) &&
	get_value(car, 1, vm, car->position + car->param[1].integer))
	{
		car->reg[num].integer = car->value[1];
		car->carry = car->reg[num].integer == 0 ? true : false;
		if (verbose_mode(vm))
			ft_printf("P %4d | lld %d r%d\n", car->number,
			car->reg[num].integer, num);
	}
}

void	cw_ld(t_car *car, t_vm *vm)
{
	int num;

	if (valid_reg(num = car->param[2].integer))
	{
		get_value(car, 1, vm,
			car->position + car->param[1].integer % IDX_MOD);
		car->reg[num].integer = car->value[1];
		car->carry = car->reg[num].integer == 0 ? true : false;
		if (verbose_mode(vm))
			ft_printf("P %4d | ld %d r%d\n", car->number,
			car->reg[num].integer, car->param[2].integer);
	}
}
