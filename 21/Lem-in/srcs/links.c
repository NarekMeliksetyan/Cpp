/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:02:42 by jkrypto           #+#    #+#             */
/*   Updated: 2020/03/14 15:44:31 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static size_t	get_len(char *str)
{
	size_t	len;

	len = 0;
	while (*str && *str != '-')
	{
		++len;
		++str;
	}
	if (!(*str))
		error(1);
	return (len);
}

static t_rooms	*get_room(t_rooms **r_array, size_t i, char *str, size_t len)
{
	t_rooms *room;

	room = r_array[i];
	while (room && !(ft_strnequ(room->name, str, len)))
		room = room->next;
	if (!room)
		error(1);
	return (room);
}

static void		check_dup(t_link *link)
{
	t_rooms	*room;
	t_rooms	*nei;
	t_door	*door;

	room = link->r1;
	nei = link->r2;
	door = room->links;
	while (door)
	{
		if (door->link->r1 == nei || door->link->r2 == nei)
			error(4);
		door = door->next;
	}
}

static void		create_door(t_link *link, t_rooms *room)
{
	t_door *door;

	if (!(door = (t_door *)malloc(sizeof(t_door))))
		error(1);
	door->room = room;
	door->link = link;
	door->access = 1;
	door->next = room->links;
	room->links = door;
	door->saved = 0;
}

void			create_link(t_lemin *lemin, char *str)
{
	t_link	*link;
	size_t	len1;
	size_t	len2;
	size_t	i1;
	size_t	i2;

	len1 = get_len(str);
	len2 = ft_strlen(str + len1 + 1);
	i1 = hash_code(str, lemin->rooms_num, len1);
	i2 = hash_code(str + len1 + 1, lemin->rooms_num, len2);
	if (!(link = (t_link *)malloc(sizeof(t_link))))
		error(1);
	link->r1 = get_room(lemin->r_array, i1, str, len1);
	link->r2 = get_room(lemin->r_array, i2, str + len1 + 1, len2);
	link->weight = 1;
	link->deleted = 0;
	link->saved = 0;
	link->visit = 0;
	save_str(lemin, str);
	check_dup(link);
	create_door(link, link->r1);
	create_door(link, link->r2);
}
