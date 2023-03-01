/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:06:48 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:44:42 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	dump(t_vm *vm)
{
	int		i;

	i = -1;
	if (!vm->flag_visual && !vm->flag_verbose)
	{
		while (++i < MEM_SIZE)
		{
			if (i % 64 == 0)
			{
				if (i == 0)
					ft_printf("0x0000 : ");
				else
					ft_printf("\n%#06x : ", i);
			}
			ft_printf("%02x ", vm->map[i]->value);
		}
		ft_printf("\n");
	}
}

void	verbose_win(t_vm *vm)
{
	if (!vm->flag_visual &&
	(vm->flag_dump == -1 || vm->flag_dump >= vm->cycle))
	{
		ft_printf("Contestant %d, \"%s\", has won !\n",
			vm->last_live->number, vm->last_live->header->prog_name);
	}
}

void	load(t_vm *vm, t_champ **list, t_bool visual)
{
	int		i;
	t_champ	*current;

	if (!visual)
	{
		i = -1;
		ft_printf("Introducing contestants...\n");
		while (list[++i])
		{
			current = find_champ(-(i + 1), vm);
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				i + 1, current->header->prog_size,
				current->header->prog_name, current->header->comment);
		}
	}
}

void	adv(t_vm *vm, int len, t_car *car)
{
	int		j;

	if (verbose_mode(vm))
	{
		ft_printf("ADV %d (", len);
		if (car->position == 0)
			ft_printf("0x0000");
		else
			ft_printf("%#06x", car->position);
		ft_printf(" -> ");
		if (car->position + len == 0)
			ft_printf("0x0000");
		else
			ft_printf("%#06x", car->position + len);
		ft_printf(") ");
		j = -1;
		while (++j < len)
			ft_printf("%02x ", vm->map[(car->position + j) % MEM_SIZE]->value);
		ft_printf("\n");
	}
}
