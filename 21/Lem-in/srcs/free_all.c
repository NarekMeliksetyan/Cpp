/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 14:53:36 by ifran             #+#    #+#             */
/*   Updated: 2020/03/14 14:53:52 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	free_links_and_q(t_lemin *lemin)
{
	t_queue *q;

	links_to_queue(lemin);
	while ((q = lemin->q_start))
	{
		lemin->q_start = lemin->q_start->next;
		if (q->to_delete)
			free(q->door->link);
		free(q);
	}
}

static void	free_doors(t_door *door)
{
	t_door *tmp;

	while ((tmp = door))
	{
		door = door->next;
		free(tmp);
	}
}

static void	free_rooms(t_lemin *lemin)
{
	size_t	i;
	t_rooms *room;
	t_rooms *tmp;

	i = 0;
	while (i < lemin->rooms_num)
	{
		room = lemin->r_array[i];
		while (room)
		{
			tmp = room;
			room = room->next;
			free_doors(tmp->links);
			free(tmp->name);
			free(tmp);
		}
		++i;
	}
	free(lemin->r_array);
}

static void	free_sol(t_paths **sol, int max)
{
	int		i;
	t_paths *path;
	t_paths	*tmp;

	i = 0;
	while (i < max)
	{
		path = sol[i];
		while (path)
		{
			tmp = path;
			path = path->next;
			free(tmp);
		}
		++i;
	}
	free(sol);
}

void		go_free(t_lemin *lemin)
{
	free_links_and_q(lemin);
	free_rooms(lemin);
	free_sol(lemin->cur_sol, lemin->max_paths);
	free_sol(lemin->next_sol, lemin->max_paths);
	free(lemin);
}
