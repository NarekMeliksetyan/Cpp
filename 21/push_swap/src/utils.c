/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:18:31 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 20:03:22 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack **st)
{
	t_stack	*next;

	while (*st)
	{
		next = (*st)->next;
		free(*st);
		*st = next;
	}
}

int			free_stacks(t_stacks **sts, int ret_val)
{
	if (*sts && (*sts)->a)
		free_stack(&(*sts)->a);
	if (*sts && (*sts)->b)
		free_stack(&(*sts)->b);
	if (*sts)
		free(*sts);
	return (ret_val);
}

void		error(void)
{
	ft_putendl_fd("\e[31mError\e[0m", 1);
	exit(1);
}

int			set_tmp_cmds(t_stacks *sts, t_stack *tmp_b)
{
	sts->tmp_pl = get_node_place_i(sts->a, tmp_b->val);
	sts->tmp_b = node_iter_to_up(sts->len_b, tmp_b->top);
	sts->tmp_a = node_iter_to_up(sts->len_a, sts->tmp_pl);
	return (node_b_to_a_count(sts->tmp_a, sts->tmp_b, sts->tmp_pl));
}

void		copy_tmp_to_opt_cmds(t_stacks *sts)
{
	sts->opt_pl = sts->tmp_pl;
	sts->opt_b = sts->tmp_b;
	sts->opt_a = sts->tmp_a;
}
