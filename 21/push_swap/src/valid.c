/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:18:38 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 17:41:20 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_valid_int(int val_i, char *val_c)
{
	char	*cur_val;
	int		res;

	res = 0;
	cur_val = ft_itoa(val_i);
	if (ft_strcmp(cur_val, val_c) == 0)
		res = 1;
	if (cur_val)
		free(cur_val);
	return (!res);
}

int	is_dupl(t_stack *st, int val)
{
	while (st)
	{
		if (st->val == val)
			return (1);
		st = st->next;
	}
	return (0);
}

int	sorted_stacks(t_stacks *sts)
{
	t_stack	*st_a;
	int		last_val;

	if (sts->b)
		return (0);
	st_a = sts->a;
	last_val = st_a->val;
	while (st_a)
	{
		if (last_val > st_a->val)
			return (0);
		last_val = st_a->val;
		st_a = st_a->next;
	}
	return (1);
}
