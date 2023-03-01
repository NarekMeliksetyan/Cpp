/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_to_q.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 14:53:03 by ifran             #+#    #+#             */
/*   Updated: 2020/03/14 14:53:29 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static t_queue	*new_fq_elem(t_door *door, int iter)
{
	t_queue *elem;

	if (!(elem = (t_queue *)malloc(sizeof(t_queue))))
		error(1);
	elem->iter = iter;
	elem->door = door;
	elem->to_delete = 1;
	elem->next = NULL;
	return (elem);
}

static void		get_all_links(t_queue **q_end, t_door *door, int visit)
{
	while (door)
	{
		if (!door->link->visit)
		{
			if (!((*q_end)->next))
				(*q_end)->next = new_fq_elem(door, visit);
			else
			{
				(*q_end)->next->door = door;
				(*q_end)->next->iter = visit;
				(*q_end)->next->to_delete = 1;
			}
			door->link->visit = 1;
			*q_end = (*q_end)->next;
		}
		door = door->next;
	}
}

static void		update_q(t_queue *q, t_queue **q_end, int visit)
{
	t_rooms *room;
	t_rooms *nei;

	room = q->door->room;
	nei = room == q->door->link->r1 ? q->door->link->r2 : q->door->link->r1;
	get_all_links(q_end, nei->links, visit);
}

void			links_to_queue(t_lemin *lemin)
{
	int		visit;
	t_queue *q;
	t_queue	*q_end;

	visit = --lemin->cur_iter_bfs;
	q = lemin->q_start;
	q->to_delete = 1;
	q->door->link->visit = 1;
	q->iter = visit;
	q_end = q;
	get_all_links(&q_end, q->door, visit);
	while (q && q->iter == visit)
	{
		update_q(q, &q_end, visit);
		q = q->next;
	}
}
