/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 14:54:01 by ifran             #+#    #+#             */
/*   Updated: 2020/03/14 14:54:31 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_ant_path	*ant_struct(t_lemin *lemin, t_ant_path *ant_path)
{
	t_ant_path	*ret;
	int			i_path;

	i_path = 0;
	if (!(ant_path = (t_ant_path *)malloc(sizeof(t_ant_path))))
		error(1);
	ret = ant_path;
	while (i_path < lemin->cur_paths)
	{
		ant_path->path = lemin->cur_sol[i_path];
		ant_path->ant = NULL;
		ant_path->last_ant = NULL;
		if (i_path + 1 < lemin->cur_paths)
		{
			if (!(ant_path->next = (t_ant_path *)malloc(sizeof(t_ant_path))))
				error(1);
		}
		else
			ant_path->next = NULL;
		++i_path;
		ant_path = ant_path->next;
	}
	return (ret);
}

t_ant		*new_ant(t_ant_path *ant_path, int i)
{
	t_ant *new;

	if (!(new = (t_ant *)malloc(sizeof(t_ant))))
		error(1);
	new->i = i;
	new->room = ant_path->path;
	new->next = NULL;
	return (new);
}

void		free_ants(t_ant_path *ant_path)
{
	t_ant_path *path;

	while (ant_path)
	{
		path = ant_path->next;
		free(ant_path);
		ant_path = path;
	}
}
