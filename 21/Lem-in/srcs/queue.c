/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:58:57 by ifran             #+#    #+#             */
/*   Updated: 2020/03/05 19:08:20 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_queue	*create_q_elem(t_door *door, int flag, int iter)
{
	t_queue *elem;

	if (!(elem = (t_queue *)malloc(sizeof(t_queue))))
		error(1);
	elem->iter = iter;
	elem->door = door;
	elem->suurballe = flag;
	elem->to_delete = 0;
	elem->next = NULL;
	return (elem);
}
