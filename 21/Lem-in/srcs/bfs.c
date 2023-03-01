/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:59:54 by ifran             #+#    #+#             */
/*   Updated: 2020/03/05 20:34:42 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		to_queue(t_queue **q_end, t_door *door, int visit)
{
	if ((*q_end)->next)
	{
		(*q_end)->next->door = door;
		(*q_end)->next->suurballe = 0;
		(*q_end)->next->iter = visit;
		(*q_end)->next->to_delete = 0;
	}
	else
		(*q_end)->next = create_q_elem(door, 0, visit);
	*q_end = (*q_end)->next;
}

static int		solve(t_queue *q, t_queue **q_end, int visit, int save)
{
	t_door	*door;
	t_rooms	*nei;

	door = q->door;
	while (door)
	{
		if (!door->access || door->link->deleted ||\
		(save && (door->link->saved == save || door->link->weight == 1)))
		{
			door = door->next;
			continue;
		}
		nei = door->link->r1 == door->room ? door->link->r2 : door->link->r1;
		if (nei->visit != visit && (nei->visit = visit))
		{
			nei->prev = door;
			if ((!save && nei->end) || (save && nei->start))
				return (1);
			to_queue(q_end, nei->links, visit);
		}
		door = door->next;
	}
	return (0);
}

void			bfs(t_lemin *lemin, int flag)
{
	t_queue *queue;
	t_queue *q_end;
	int		visit;

	lemin->end_r->prev = NULL;
	visit = --(lemin->cur_iter_bfs);
	if (!(queue = lemin->q_start))
	{
		if (!flag)
			queue = create_q_elem(lemin->start_r->links, 0, visit);
		else
			queue = create_q_elem(lemin->end_r->links, 0, visit);
		lemin->q_start = queue;
	}
	queue->iter = visit;
	queue->door = flag ? lemin->end_r->links : lemin->start_r->links;
	q_end = queue;
	while (queue && queue->iter == visit)
	{
		if (solve(queue, &q_end, visit, flag))
			break ;
		queue = queue->next;
	}
}
