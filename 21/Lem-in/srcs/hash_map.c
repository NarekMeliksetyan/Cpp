/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:57:34 by ifran             #+#    #+#             */
/*   Updated: 2020/03/14 15:44:24 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

unsigned long long		hash_code(char *str, size_t r_num, size_t len)
{
	unsigned long long				iter;
	unsigned long long				power;
	unsigned long long				hashcode;

	if (!str)
		error(1);
	hashcode = 0;
	iter = 0;
	power = ft_ull_pow(31, len - 1);
	while (iter < len)
	{
		hashcode += str[iter] * power;
		++iter;
		power /= 31;
	}
	hashcode %= r_num;
	return (hashcode);
}

static void				check_dup(t_rooms *rooms, t_rooms *r)
{
	while (rooms)
	{
		if (ft_strequ(rooms->name, r->name))
			error(3);
		rooms = rooms->next;
	}
}

void					create_hash_map(t_lemin *lemin)
{
	t_rooms				*room;
	t_rooms				*temp;
	t_rooms				*check;
	unsigned long long	hashcode;
	size_t				r_num;

	r_num = 0;
	if (!(lemin->r_array = (t_rooms **)malloc(sizeof(t_rooms *)\
					* lemin->rooms_num)))
		error(1);
	room = lemin->r_list;
	while (r_num < lemin->rooms_num)
		lemin->r_array[r_num++] = NULL;
	while (room)
	{
		temp = room->next;
		hashcode = hash_code(room->name,\
				lemin->rooms_num, ft_strlen(room->name));
		check = lemin->r_array[hashcode];
		check_dup(check, room);
		room->next = check;
		lemin->r_array[hashcode] = room;
		room = temp;
	}
}
