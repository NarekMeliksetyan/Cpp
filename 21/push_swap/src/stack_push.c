/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:18:26 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 18:04:40 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			push_back(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = get_last_node(*stack);
	last->next = new;
}

void			push_front(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

t_stack			*push_back_int(t_stack **stack, int val)
{
	t_stack *new;

	if ((new = create_new_node(val)) == NULL)
		return (NULL);
	push_back(stack, new);
	return (*stack);
}
