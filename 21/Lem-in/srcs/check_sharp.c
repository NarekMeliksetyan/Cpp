/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sharp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:31:27 by jkrypto           #+#    #+#             */
/*   Updated: 2020/03/05 02:20:31 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			cr_start_end(t_lemin *lemin, char *str, int flag)
{
	if ((flag == 1 && lemin->start_r) || (flag == 2 && lemin->end_r))
		error(1);
	save_str(lemin, str);
	get_next_line(lemin->fd, &str);
	while (*str == '#')
	{
		save_str(lemin, str);
		get_next_line(lemin->fd, &str);
	}
	create_room(lemin, str, flag);
	if (flag == 1)
		lemin->start_r = lemin->r_list;
	else if (flag == 2)
		lemin->end_r = lemin->r_list;
}

int					check_sharp(t_lemin *lemin, char *str)
{
	if (*str == '#')
	{
		if (*(str + 1) && *(str + 1) == '#')
		{
			if (*(str + 2) && ft_strequ(str + 2, "start"))
				cr_start_end(lemin, str, 1);
			else if (*(str + 2) && ft_strequ(str + 2, "end"))
				cr_start_end(lemin, str, 2);
			else
				save_str(lemin, str);
		}
		else
			save_str(lemin, str);
		return (1);
	}
	return (0);
}
