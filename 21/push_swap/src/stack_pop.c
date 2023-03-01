/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:18:16 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 18:05:04 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*pop_front(t_stack **stack)
{
	t_stack *tmp;

	if (*stack == NULL)
		return (NULL);
	tmp = *stack;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
		*stack = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

t_stack			*pop_back(t_stack **stack)
{
	t_stack *pre_last;
	t_stack *tmp;

	pre_last = *stack;
	tmp = *stack;
	if (*stack == NULL)
		return (NULL);
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		while (pre_last->next && pre_last->next->next)
			pre_last = pre_last->next;
		tmp = pre_last->next;
		pre_last->next = NULL;
	}
	return (tmp);
}
