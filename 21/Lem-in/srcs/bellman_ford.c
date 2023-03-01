/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:55:05 by ifran             #+#    #+#             */
/*   Updated: 2020/03/04 18:55:42 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		s_check(t_door *door, t_rooms *nei)
{
	if (door->link->weight == 1 && nei->min_path)
		return (1);
	return (0);
}

static void		to_queue(t_queue **q_end, t_door *door, t_rooms *nei, int iter)
{
	if ((*q_end)->next)
	{
		(*q_end)->next->door = nei->links;
		(*q_end)->next->suurballe = s_check(door, nei);
		(*q_end)->next->iter = iter;
	}
	else
		(*q_end)->next = create_q_elem(nei->links, s_check(door, nei), iter);
	*q_end = (*q_end)->next;
}

static void		solve(t_queue *q, t_queue **q_end, int visit)
{
	t_door	*door;
	t_rooms *room;
	t_rooms *nei;

	door = q->door;
	room = door->room;
	while (door)
	{
		if (!door->access || door->link->deleted ||\
			(q->suurballe && door->link->weight == 1))
		{
			door = door->next;
			continue;
		}
		nei = room == door->link->r1 ? door->link->r2 : door->link->r1;
		if ((nei->visit < visit && (nei->visit = visit))\
			|| nei->min_steps > room->min_steps + door->link->weight)
		{
			nei->prev = door;
			nei->min_steps = room->min_steps + door->link->weight;
			if (!nei->end)
				to_queue(q_end, door, nei, visit);
		}
		door = door->next;
	}
}

int				bellman_ford(t_lemin *lemin)
{
	t_queue *queue;
	t_queue	*q_end;
	int		iter;

	lemin->end_r->prev = NULL;
	iter = ++lemin->cur_iter_bf;
	if (!(queue = lemin->q_start))
	{
		queue = create_q_elem(lemin->start_r->links, 0, iter);
		lemin->q_start = queue;
	}
	queue->iter = iter;
	queue->door = lemin->start_r->links;
	lemin->start_r->visit = iter;
	q_end = queue;
	while (queue && queue->iter == iter)
	{
		solve(queue, &q_end, iter);
		queue = queue->next;
	}
	if (!(lemin->end_r->prev))
		return (0);
	return (1);
}
