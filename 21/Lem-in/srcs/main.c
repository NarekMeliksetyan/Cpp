/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:26:58 by jkrypto           #+#    #+#             */
/*   Updated: 2020/03/14 15:51:34 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		get_ants_n(t_lemin *lemin)
{
	char *str;
	char *check;

	get_next_line(lemin->fd, &str);
	save_str(lemin, str);
	while (*str == '#')
	{
		get_next_line(lemin->fd, &str);
		save_str(lemin, str);
	}
	if (!ft_isnumber(str))
		error(1);
	check = str;
	while (*check == '0')
		++check;
	if (ft_strlen(check) > 10)
		error(1);
	lemin->ants = ft_atoi(str);
	if (lemin->ants <= 0)
		error(1);
}

static void		struct_init(t_lemin *lemin)
{
	lemin->file = NULL;
	lemin->file_end = NULL;
	lemin->rooms_num = 0;
	lemin->cur_iter_bfs = 0;
	lemin->cur_iter_bf = 0;
	lemin->cur_paths = 0;
	lemin->max_paths = 0;
	lemin->start_r = NULL;
	lemin->end_r = NULL;
	lemin->r_list = NULL;
	lemin->r_array = NULL;
	lemin->q_start = NULL;
	lemin->cur_sol = NULL;
	lemin->next_sol = NULL;
}

static void		file_output(t_lemin *lemin)
{
	t_strings	*file;

	while ((file = lemin->file))
	{
		ft_putendl(file->str);
		free(file->str);
		lemin->file = lemin->file->next;
		free(file);
	}
}

static int		check_input(int ac, char **av)
{
	int fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			error(2);
		return (fd);
	}
	else if (ac > 2)
		error(7);
	return (0);
}

int				main(int argc, char **argv)
{
	t_lemin *lemin;

	if (!(lemin = (t_lemin *)malloc(sizeof(t_lemin))))
		error(1);
	lemin->fd = check_input(argc, argv);
	struct_init(lemin);
	get_ants_n(lemin);
	parse_map(lemin);
	close(lemin->fd);
	suurballe(lemin);
	file_output(lemin);
	ft_putchar('\n');
	go_ants(lemin);
	go_free(lemin);
	return (0);
}
