/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:18:08 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 18:03:17 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

t_stack			*create_new_node(int val)
{
	t_stack *new;

	if ((new = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	new->val = val;
	new->top = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_stack			*get_last_node(t_stack *st)
{
	while (st->next)
		st = st->next;
	return (st);
}

int				get_count_nodes(t_stack *st)
{
	int count;

	count = 0;
	while (st)
	{
		st = st->next;
		count++;
	}
	return (count);
}

static void		create_stack_a(int ac, char **av, t_stacks *sts)
{
	int i;
	int cur_val;

	av = ac == 2 ? ft_strsplit(av[1], ' ') : av;
	i = ac == 2 ? 0 : 1;
	while ((ac == 2 ? (int)av[i] : i < ac))
	{
		if (ft_strcmp(av[i], "-v") == 0)
			sts->flag_v = 1;
		else
		{
			cur_val = ft_atoi(av[i]);
			if (not_valid_int(cur_val, av[i]) ||
				is_dupl(sts->a, cur_val))
				error();
			if ((push_back_int(&sts->a, cur_val)) == NULL)
				error();
		}
		i++;
	}
	ft_free_array(ac == 2 ? av : NULL, 1);
	if (*av == NULL)
		exit(1);
}

t_stacks		*create_stacks(int ac, char **av)
{
	t_stacks *sts;

	if ((sts = (t_stacks*)malloc(sizeof(t_stacks))) == NULL)
		error();
	sts->a = NULL;
	sts->b = NULL;
	sts->flag_v = 0;
	sts->cmds_cnt = 0;
	sts->cmd_print = 0;
	create_stack_a(ac, av, sts);
	return (sts);
}
