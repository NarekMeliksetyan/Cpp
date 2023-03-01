/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:08:06 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:43:12 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		ft_error_exit(char *message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(message, 2);
	exit(0);
}

void		usage(void)
{
	ft_printf("Usage: ./corewar <[-n number] champion1.cor> <...> [-verbose] \
					[-visual] [-dump cycle_number]\n");
	exit(0);
}

void		cleen_all(t_vm *war)
{
	int		i;
	t_car	*tmp;
	t_car	*buf;

	i = -1;
	while (++i < MEM_SIZE)
		ft_memdel((void**)&war->map[i]);
	i = -1;
	while (++i < war->count_champ)
	{
		ft_memdel((void**)&war->champs[i]->header);
		ft_memdel((void**)&war->champs[i]);
	}
	tmp = war->cars;
	while (tmp)
	{
		buf = tmp;
		free(buf);
		tmp = tmp->next;
	}
	ft_memdel((void**)&war);
}
