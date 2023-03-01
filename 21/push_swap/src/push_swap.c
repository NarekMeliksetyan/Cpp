/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:17:37 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 18:17:06 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stacks *sts)
{
	if (sts->a->val > sts->a->next->val &&
		sts->a->val < sts->a->next->next->val)
		cmd_apply_cnt("sa", 1, sts);
	else if (sts->a->val > sts->a->next->next->val)
		cmd_apply_cnt("ra", 1, sts);
}

static void	sort_five(t_stacks *sts)
{
	if (sts->max_sort->sort < 3)
	{
		cmd_apply_cnt("pb", 2, sts);
		sort_three(sts);
	}
	else
		a_to_b(sts);
	b_to_a(sts);
	a_min_to_top(sts);
}

static void	sort_other(t_stacks *sts)
{
	a_to_b(sts);
	b_to_a(sts);
	a_min_to_top(sts);
}

int			main(int ac, char **av)
{
	t_stacks *sts;

	if (ac < 2 || !*(av[1]))
		return (0);
	sts = create_stacks(ac, av);
	if (sts->a == NULL)
		exit(0);
	sts->cmd_print = 1;
	sts->len_a = get_count_nodes(sts->a);
	a_norm(sts);
	if (sts->len_a == 3)
		sort_three(sts);
	else if (sts->len_a == 5)
		sort_five(sts);
	else
		sort_other(sts);
	return (free_stacks(&sts, 0));
}
