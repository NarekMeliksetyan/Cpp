/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sols_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:59:10 by ifran             #+#    #+#             */
/*   Updated: 2020/03/04 19:22:29 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		init(t_lemin *lemin, int flag, int num)
{
	t_paths **sol;
	int		i;

	sol = flag ? lemin->next_sol : lemin->cur_sol;
	i = 0;
	while (i < num)
	{
		if (!(sol[i] = (t_paths *)malloc(sizeof(t_paths))))
			error(1);
		sol[i]->ant = 0;
		sol[i]->ants = 0;
		sol[i]->len = 0;
		sol[i]->room = NULL;
		sol[i]->next = NULL;
		++i;
	}
}

void			create_sols_mem(t_lemin *lemin, int num)
{
	if (!(lemin->cur_sol = (t_paths **)malloc(sizeof(t_paths *) * num)))
		error(1);
	if (!(lemin->next_sol = (t_paths **)malloc(sizeof(t_paths *) * num)))
		error(1);
	init(lemin, 0, num);
	init(lemin, 1, num);
}
