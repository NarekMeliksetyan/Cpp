/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:17:48 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 18:16:22 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_norm(t_stacks *sts)
{
	int com;

	set_index(sts->a);
	sts->max_sort = get_max_sort(sts->a);
	sts->len_a = get_count_nodes(sts->a);
	com = sts->len_a - sts->max_sort->top - sts->max_sort->sort > 0 ?
		sts->len_a - (sts->len_a - sts->max_sort->top - sts->max_sort->sort) :
		abs(sts->len_a - sts->max_sort->top - sts->max_sort->sort);
	com = node_iter_to_up(sts->len_a, com);
	cmd_apply_cnt(com > 0 ? "ra" : "rra", com, sts);
}

void	a_to_b(t_stacks *sts)
{
	t_stack *st_a;

	st_a = sts->a;
	while (st_a && st_a->top != sts->max_sort->top)
	{
		st_a = st_a->next;
		cmd_apply_cnt("pb", 1, sts);
	}
}

void	node_b_to_a(t_stacks *sts)
{
	sts->tmp_b = ft_abs(sts->opt_b);
	sts->tmp_a = ft_abs(sts->opt_a);
	while (((sts->opt_b > 0 && sts->opt_a > 0) || (sts->opt_b < 0 &&
			sts->opt_a < 0)) && sts->tmp_b && sts->tmp_a && sts->opt_pl != -1)
	{
		cmd_apply_cnt(sts->opt_b > 0 ? "rr" : "rrr", 1, sts);
		sts->tmp_b--;
		sts->tmp_a--;
	}
	cmd_apply_cnt(sts->opt_b > 0 ? "rb" : "rrb", sts->tmp_b, sts);
	if (sts->opt_pl != -1)
		cmd_apply_cnt(sts->opt_a > 0 ? "ra" : "rra", sts->tmp_a, sts);
	cmd_apply_cnt("pa", 1, sts);
	if (sts->opt_pl == -1)
		cmd_apply_cnt("ra", 1, sts);
}

void	b_to_a(t_stacks *sts)
{
	t_stack *tmp_b;
	int		min_cmds;
	int		cmds;

	while (sts->b)
	{
		tmp_b = sts->b;
		set_index(sts->a);
		set_index(sts->b);
		sts->len_a = get_count_nodes(sts->a);
		sts->len_b = get_count_nodes(sts->b);
		min_cmds = set_tmp_cmds(sts, tmp_b);
		copy_tmp_to_opt_cmds(sts);
		while (tmp_b)
		{
			cmds = set_tmp_cmds(sts, tmp_b);
			if (min_cmds > cmds)
			{
				min_cmds = cmds;
				copy_tmp_to_opt_cmds(sts);
			}
			tmp_b = tmp_b->next;
		}
		node_b_to_a(sts);
	}
}

void	a_min_to_top(t_stacks *sts)
{
	t_stack	*tmp_a;
	t_stack	*min_node;
	int		iter_to_up;

	tmp_a = sts->a;
	min_node = tmp_a;
	while (tmp_a)
	{
		min_node = tmp_a->val < min_node->val ? tmp_a : min_node;
		tmp_a = tmp_a->next;
	}
	sts->len_a = get_count_nodes(sts->a);
	set_index(sts->a);
	iter_to_up = node_iter_to_up(sts->len_a, min_node->top);
	cmd_apply_cnt(iter_to_up > 0 ? "ra" : "rra", iter_to_up, sts);
}
