/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:53:08 by ifran             #+#    #+#             */
/*   Updated: 2020/03/14 15:46:14 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	count_paths(t_lemin *lemin)
{
	int			start_p;
	int			end_p;
	t_door		*door;

	start_p = 0;
	end_p = 0;
	door = lemin->start_r->links;
	while (door)
	{
		++start_p;
		door = door->next;
	}
	door = lemin->end_r->links;
	while (door)
	{
		++end_p;
		door = door->next;
	}
	return (start_p < end_p ? start_p : end_p);
}

static int	check_break(t_lemin *lemin)
{
	t_paths **swp;
	int		res;

	if (!(res = check_solution(lemin)))
	{
		--lemin->cur_paths;
		return (1);
	}
	swp = lemin->cur_sol;
	lemin->cur_sol = lemin->next_sol;
	lemin->next_sol = swp;
	if (res > 0)
		return (1);
	return (0);
}

static int	find_first_path(t_lemin *lemin, t_rooms *room)
{
	int		len;
	t_door	*door;
	t_rooms	*nei;

	len = 1;
	door = room->prev;
	while (room != lemin->start_r)
	{
		nei = room == door->link->r1 ? door->link->r2 : door->link->r1;
		door = nei->prev;
		nei->prev = room->links;
		room = nei;
		++len;
	}
	return (len);
}

static void	save_first_path(t_lemin *lemin)
{
	t_paths *path;
	t_rooms *room;

	path = (lemin->cur_sol)[0];
	path->len = find_first_path(lemin, lemin->end_r);
	path->ants = lemin->ants;
	room = lemin->start_r;
	while (room != lemin->end_r)
	{
		path->room = room;
		if (!(path->next = (t_paths *)malloc(sizeof(t_paths))))
			error(1);
		room = room->prev->room;
		path = path->next;
	}
	path->room = room;
	path->next = NULL;
}

void		suurballe(t_lemin *lemin)
{
	int		num_paths;
	int		save_iter;

	save_iter = 0;
	num_paths = count_paths(lemin);
	lemin->max_paths = num_paths;
	create_sols_mem(lemin, num_paths);
	bfs(lemin, 0);
	if (!(lemin->end_r->prev))
		error(6);
	lemin->cur_paths = 1;
	change_path(lemin);
	save_first_path(lemin);
	if (lemin->ants == 1)
		return ;
	while (lemin->cur_paths < num_paths && bellman_ford(lemin))
	{
		++lemin->cur_paths;
		change_path(lemin);
		save_solution(lemin, ++save_iter);
		if (check_break(lemin))
			break ;
	}
}
