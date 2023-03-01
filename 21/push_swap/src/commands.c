/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:17:24 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 17:47:43 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		cmd_print(char *com)
{
	ft_putstr(com);
	ft_putchar('\n');
}

static int		cmd_apply(char *com, t_stacks *sts)
{
	int	len;
	int	res;

	len = ft_strlen(com);
	res = 0;
	if (len == 2 && com[0] == 's' && (com[1] == 's' || com[1] == 'a'))
		res = cmd_apply_s(&sts->a);
	if (len == 2 && com[0] == 's' && (com[1] == 's' || com[1] == 'b'))
		res = cmd_apply_s(&sts->b);
	if (len == 2 && com[0] == 'p' && com[1] == 'a')
		res = cmd_apply_p(&sts->b, &sts->a);
	if (len == 2 && com[0] == 'p' && com[1] == 'b')
		res = cmd_apply_p(&sts->a, &sts->b);
	if (len == 2 && com[0] == 'r' && (com[1] == 'r' || com[1] == 'a'))
		res = cmd_apply_r(&sts->a);
	if (len == 2 && com[0] == 'r' && (com[1] == 'r' || com[1] == 'b'))
		res = cmd_apply_r(&sts->b);
	if (len == 3 && com[0] == 'r' && com[1] == 'r' &&
		(com[2] == 'r' || com[2] == 'a'))
		res = cmd_apply_rr(&sts->a);
	if (len == 3 && com[0] == 'r' && com[1] == 'r' &&
		(com[2] == 'r' || com[2] == 'b'))
		res = cmd_apply_rr(&sts->b);
	return (res == 0 ? 0 : 1);
}

void			cmd_apply_cnt(char *com, int cnt, t_stacks *sts)
{
	int	i;

	i = ft_abs(cnt);
	while (i)
	{
		if (cmd_apply(com, sts))
		{
			if (sts->cmd_print == 1)
				cmd_print(com);
			if (sts->cmd_print == 0 && sts->flag_v == 1)
				put_stacks(sts);
			sts->cmds_cnt++;
		}
		else
			error();
		i--;
	}
}
