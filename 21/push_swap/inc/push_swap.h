/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:57:36 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 18:15:28 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_stack
{
	int				top;
	int				val;
	int				sort;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	int				len_a;
	int				len_b;
	int				opt_a;
	int				opt_b;
	int				tmp_a;
	int				tmp_b;
	int				tmp_pl;
	int				opt_pl;
	int				flag_v;
	int				cmds_cnt;
	int				cmd_print;
	t_stack			*a;
	t_stack			*b;
	t_stack			*max_sort;
}					t_stacks;

int					cmd_apply_s(t_stack **stack);
int					cmd_apply_r(t_stack **stack);
int					cmd_apply_rr(t_stack **stack);
int					cmd_apply_p(t_stack **from, t_stack **to);
void				cmd_apply_cnt(char *com, int cnt, t_stacks *sts);

int					node_iter_to_up(int st_len, int node_i);
int					get_node_place_i(t_stack *st, int node_val);
int					node_b_to_a_count(int a, int b, int place_b);
void				set_index(t_stack *st);
t_stack				*get_max_sort(t_stack *st);

int					set_tmp_cmds(t_stacks *sts, t_stack *tmp_b);
void				copy_tmp_to_opt_cmds(t_stacks *sts);

void				a_norm(t_stacks *sts);
void				a_to_b(t_stacks *sts);
void				b_to_a(t_stacks *sts);
void				a_min_to_top(t_stacks *sts);
void				node_b_to_a(t_stacks *sts);

void				push_back(t_stack **stack, t_stack *new);
void				push_front(t_stack **stack, t_stack *new);

t_stack				*pop_front(t_stack **stack);
t_stack				*pop_back(t_stack **stack);
t_stack				*push_back_int(t_stack **stack, int val);

int					get_count_nodes(t_stack *st);
t_stack				*create_new_node(int val);
t_stack				*get_last_node(t_stack *st);
t_stacks			*create_stacks(int ac, char **av);

int					free_stacks(t_stacks **sts, int ret_val);
void				error(void);

int					not_valid_int(int val_i, char *val_c);
int					is_dupl(t_stack *st, int val);
int					sorted_stacks(t_stacks *sts);

void				put_stacks(t_stacks *sts);

#endif
