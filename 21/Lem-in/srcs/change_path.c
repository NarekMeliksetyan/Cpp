/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:54:30 by ifran             #+#    #+#             */
/*   Updated: 2020/03/04 18:54:38 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	change_path(t_lemin *lemin)
{
	t_door	*door;
	t_rooms	*nei;
	t_rooms *room;

	room = lemin->end_r;
	while (room != lemin->start_r)
	{
		room->min_path = 1;
		door = room->prev;
		nei = door->room;
		door->access = 0;
		if (door->link->weight == -1)
			door->link->deleted = 1;
		else
			door->link->weight = -1;
		room = nei;
	}
}
