/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:29:25 by jkrypto           #+#    #+#             */
/*   Updated: 2020/03/05 02:20:24 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char			*get_name(char **str)
{
	size_t	len;
	char	*name;
	char	*start;

	len = 0;
	start = *str;
	if (*start == 'L')
		error(1);
	while (**str && **str != ' ')
	{
		*str += 1;
		len++;
	}
	if (!**str)
		error(1);
	*str = start;
	name = ft_strsub(*str, 0, len);
	*str += len;
	return (name);
}

static char			*check_move(char *str)
{
	while (*str != ' ' && *str)
	{
		if (!(ft_isdigit(*str)))
			error(1);
		++str;
	}
	return (str);
}

static void			get_coordinates(t_rooms *temp, char *str)
{
	if (*str++ != ' ')
		error(1);
	temp->x = ft_atoi(str);
	str = check_move(str);
	if (!(*str) || *str++ != ' ')
		error(1);
	temp->y = ft_atoi(str);
	str = check_move(str);
	if (*str)
		error(1);
}

void				create_room(t_lemin *lemin, char *str, int flag)
{
	t_rooms			*next;
	char			*name;
	char			*to_save;

	to_save = str;
	name = get_name(&str);
	next = lemin->r_list;
	if (!(lemin->r_list = (t_rooms *)malloc(sizeof(t_rooms))))
		error(1);
	lemin->r_list->x = 0;
	lemin->r_list->y = 0;
	lemin->r_list->index = 0;
	lemin->r_list->start = flag == 1 ? 1 : 0;
	lemin->r_list->end = flag == 2 ? 1 : 0;
	lemin->r_list->name = name;
	get_coordinates(lemin->r_list, str);
	lemin->r_list->min_steps = 0;
	lemin->r_list->next = next;
	(lemin->rooms_num)++;
	lemin->r_list->links = NULL;
	lemin->r_list->prev = NULL;
	lemin->r_list->visit = 0;
	lemin->r_list->min_path = 0;
	save_str(lemin, to_save);
}
