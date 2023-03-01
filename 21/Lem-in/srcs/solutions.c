/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:58:10 by jkrypto           #+#    #+#             */
/*   Updated: 2020/03/13 01:07:14 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	save_path(t_lemin *lemin, t_paths *path, int save, t_rooms *room)
{
	int		len;
	t_link	*link;
	t_paths	*curr;

	len = 1;
	curr = path;
	curr->room = room;
	while (room != lemin->end_r)
	{
		link = room->prev->link;
		link->saved = save;
		room = room == link->r1 ? link->r2 : link->r1;
		if (!(curr->next))
		{
			if (!(curr->next = (t_paths *)malloc(sizeof(t_paths))))
				error(1);
			curr->next->next = NULL;
		}
		curr->next->room = room;
		curr = curr->next;
		++len;
	}
	path->len = len;
	path->ants = 0;
}

static int	fill_res(t_lemin *lemin, int n)
{
	int	div;
	int	mod;
	int	i;
	int	ret;

	div = n / lemin->cur_paths;
	mod = n % lemin->cur_paths;
	i = 0;
	ret = div == 0 || (div == 1 && mod == 0) ? 1 : -1;
	if (div)
	{
		while (i < lemin->cur_paths)
		{
			(lemin->next_sol)[i]->ants += div;
			++i;
		}
	}
	i = 0;
	while (mod)
	{
		((lemin->next_sol)[i]->ants)++;
		++i;
		--mod;
	}
	return (ret);
}

int			check_solution(t_lemin *lemin)
{
	int		n;
	int		i;
	int		j;
	int		dif;

	i = 1;
	n = lemin->ants;
	while (i < lemin->cur_paths)
	{
		dif = (lemin->next_sol)[i]->len - (lemin->next_sol)[i - 1]->len;
		j = i - 1;
		if (dif)
		{
			while (j >= 0)
			{
				(lemin->next_sol)[j]->ants += dif;
				n -= dif;
				if (n <= 0)
					return (0);
				--j;
			}
		}
		++i;
	}
	return (fill_res(lemin, n));
}

void		save_solution(t_lemin *lemin, int iter)
{
	int		i;

	i = 0;
	while (i < lemin->cur_paths)
	{
		bfs(lemin, iter);
		save_path(lemin, (lemin->next_sol)[i], iter, lemin->start_r);
		++i;
	}
}
