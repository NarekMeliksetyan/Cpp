/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:17:15 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 18:09:50 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stacks	*sts;
	char		*command;

	if (ac < 2 || !*(av[1]))
		return (0);
	command = NULL;
	sts = create_stacks(ac, av);
	sts->cmd_print = 0;
	if (sts->a == NULL)
		exit(0);
	while (get_next_line(0, &command))
	{
		cmd_apply_cnt(command, 1, sts);
		if (command)
			free(command);
	}
	if (sorted_stacks(sts))
		ft_putendl("\e[32mOK\033[00m");
	else
		ft_putendl("\e[35mKO\033[00m");
	return (free_stacks(&sts, 0));
}
