/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:30:58 by ifran             #+#    #+#             */
/*   Updated: 2020/03/05 20:53:38 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <fcntl.h>

typedef struct			s_rooms
{
	int					index;
	char				*name;
	int					x;
	int					y;
	int					start;
	int					end;
	int					min_steps;
	int					min_path;
	int					visit;
	struct s_door		*prev;
	struct s_rooms		*next;
	struct s_door		*links;
}						t_rooms;

typedef struct			s_link
{
	t_rooms				*r1;
	t_rooms				*r2;
	int					deleted;
	int					saved;
	int					visit;
	int					weight;
}						t_link;

typedef struct			s_door
{
	t_rooms				*room;
	t_link				*link;
	int					access;
	int					saved;
	struct s_door		*next;
}						t_door;

typedef struct			s_queue
{
	int					to_delete;
	int					iter;
	int					suurballe;
	t_door				*door;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_paths
{
	int					len;
	int					ants;
	int					ant;
	t_rooms				*room;
	struct s_paths		*next;
}						t_paths;

typedef struct			s_strings
{
	char				*str;
	struct s_strings	*next;
}						t_strings;

typedef struct			s_ant
{
	int					i;
	t_paths				*room;
	struct s_ant		*next;
}						t_ant;

typedef struct			s_ant_path
{
	t_ant				*ant;
	t_ant				*last_ant;
	t_paths				*path;
	struct s_ant_path	*next;
}						t_ant_path;

typedef struct			s_lemin
{
	int					fd;
	int					ants;
	size_t				rooms_num;
	int					cur_iter_bfs;
	int					cur_iter_bf;
	int					cur_paths;
	int					max_paths;
	t_rooms				*start_r;
	t_rooms				*end_r;
	t_rooms				*r_list;
	t_rooms				**r_array;
	t_queue				*q_start;
	t_paths				**cur_sol;
	t_paths				**next_sol;
	t_strings			*file;
	t_strings			*file_end;
}						t_lemin;

void					error(int err);
void					parse_map(t_lemin *lemin);
int						check_sharp(t_lemin *lemin, char *str);
void					get_link(t_lemin *lemin, char *str);
void					create_room(t_lemin *lemin, char *str, int flag);
unsigned long long		hash_code(char *str, size_t r_num, size_t len);
void					create_hash_map(t_lemin *lemin);
void					create_link(t_lemin *lemin, char *str);
void					bfs(t_lemin *lemin, int flag);
void					change_path(t_lemin *lemin);
int						bellman_ford(t_lemin *lemin);
void					debug(t_lemin *lemin);
void					suurballe(t_lemin *lemin);
void					save_solution(t_lemin *lemin, int iter);
int						check_solution(t_lemin *lemin);
t_queue					*create_q_elem(t_door *door, int flag, int iter);
void					create_sols_mem(t_lemin *lemin, int num);
void					save_str(t_lemin *lemin, char *str);
t_ant_path				*ant_struct(t_lemin *lemin, t_ant_path *ant_path);
t_ant					*new_ant(t_ant_path *ant_path, int i);
void					go_ants(t_lemin *lemin);
void					free_ants(t_ant_path *ant_path);
void					go_free(t_lemin *lemin);
void					links_to_queue(t_lemin *lemin);

#endif
