/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:44:33 by jkrypto           #+#    #+#             */
/*   Updated: 2020/03/14 15:46:06 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		parse_map(t_lemin *lemin)
{
	char	*str;
	int		e;

	while ((e = get_next_line(lemin->fd, &str)))
	{
		if (e < 0)
			error(1);
		if (*str != '#' && !ft_strchr(str, ' '))
			break ;
		if (!check_sharp(lemin, str))
			create_room(lemin, str, 0);
	}
	if (!(lemin->end_r) || !(lemin->start_r))
		error(5);
	create_hash_map(lemin);
	while (e)
	{
		if (e < 0)
			error(1);
		if (!check_sharp(lemin, str))
			create_link(lemin, str);
		e = get_next_line(lemin->fd, &str);
	}
}
