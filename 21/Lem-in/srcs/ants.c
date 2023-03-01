/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 14:49:08 by ifran             #+#    #+#             */
/*   Updated: 2020/03/14 14:50:25 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		check_if_path_is_idiot(t_lemin *lemin)
{
	int i;

	i = 1;
	if (lemin->cur_paths == 1 && lemin->cur_sol[0]->len == 2)
	{
		while (i <= lemin->ants)
		{
			ft_putchar('L');
			ft_putnbr(i);
			ft_putchar('-');
			ft_putstr(lemin->end_r->name);
			if (i < lemin->ants)
				ft_putchar(' ');
			++i;
		}
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

static int		fill_ants(t_ant_path *a_path, int i, int max)
{
	while (i <= max && a_path && a_path->path->ants)
	{
		a_path->path->ants--;
		if (a_path->last_ant)
		{
			a_path->last_ant->next = new_ant(a_path, i);
			a_path->last_ant = a_path->last_ant->next;
		}
		else
		{
			a_path->last_ant = new_ant(a_path, i);
			a_path->ant = a_path->last_ant;
		}
		++i;
		a_path = a_path->next;
	}
	return (i);
}

void			ants_output(t_ant_path *a_path)
{
	t_ant	*ant;
	int		space;

	space = 0;
	while (a_path)
	{
		ant = a_path->ant;
		while (ant)
		{
			if (space)
				ft_putchar(' ');
			ft_putchar('L');
			ft_putnbr(ant->i);
			ft_putchar('-');
			ft_putstr(ant->room->room->name);
			if (!space)
				space = 1;
			ant = ant->next;
		}
		a_path = a_path->next;
	}
	ft_putchar('\n');
}

static int		move_ants(t_ant_path *a_path)
{
	int		ret;
	t_ant	*ant;

	ret = 1;
	while (a_path)
	{
		if (a_path->ant && a_path->ant->room->room->end)
		{
			ant = a_path->ant->next;
			free(a_path->ant);
			a_path->ant = ant;
		}
		ant = a_path->ant;
		while (ant)
		{
			ant->room = ant->room->next;
			if (ret)
				ret = 0;
			ant = ant->next;
		}
		a_path = a_path->next;
	}
	return (ret);
}

void			go_ants(t_lemin *lemin)
{
	int			to_fill;
	t_ant_path	*ant_path;
	int			i;

	if (check_if_path_is_idiot(lemin))
		return ;
	i = 1;
	ant_path = NULL;
	to_fill = lemin->ants;
	ant_path = ant_struct(lemin, ant_path);
	while (1)
	{
		if (i <= to_fill)
			i = fill_ants(ant_path, i, to_fill);
		if (move_ants(ant_path) && i > to_fill)
			break ;
		ants_output(ant_path);
	}
	free_ants(ant_path);
}
