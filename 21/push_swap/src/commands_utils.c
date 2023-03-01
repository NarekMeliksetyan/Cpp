/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:17:31 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 18:02:50 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_apply_s(t_stack **stack)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->val;
		(*stack)->val = (*stack)->next->val;
		(*stack)->next->val = tmp;
		return (1);
	}
	return (-1);
}

int	cmd_apply_r(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		push_back(stack, pop_front(stack));
		return (1);
	}
	return (-1);
}

int	cmd_apply_rr(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		push_front(stack, pop_back(stack));
		return (1);
	}
	return (-1);
}

int	cmd_apply_p(t_stack **from, t_stack **to)
{
	if (*from)
	{
		push_front(to, pop_front(from));
		return (1);
	}
	return (-1);
}
