/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:00:48 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 18:09:21 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_stack(t_stack *st)
{
	char			neg;
	unsigned int	size;

	while (st)
	{
		size = st->val > 0 ? st->val : -st->val;
		neg = st->val > 0 ? 0 : 1;
		while (size--)
			if (neg)
				ft_putstr("\e[45m \e[0m");
			else
				ft_putstr("\e[44m \e[0m");
		ft_putendl("\e[0m");
		st = st ? st->next : NULL;
	}
	ft_putchar('\n');
}

void		put_stacks(t_stacks *sts)
{
	t_stack *st_a;
	t_stack *st_b;

	st_a = sts->a;
	st_b = sts->b;
	ft_putstr("\e[1;1H\e[2J");
	ft_putendl("\e[33mA:\033[0m");
	put_stack(st_a);
	ft_putendl("\e[36mB:\033[0m");
	put_stack(st_b);
	sleep(1);
}
