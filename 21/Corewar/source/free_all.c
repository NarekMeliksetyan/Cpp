/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:04:14 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:04:16 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static	void	free_list(t_asm *asm_parsing)
{
	t_word	*current;
	t_word	*temp;
	t_label	*current_label;
	t_label	*temp_label;

	current = asm_parsing->words;
	current_label = asm_parsing->labels;
	while (current != NULL)
	{
		temp = current->next;
		ft_strdel(&current->name);
		free(current);
		current = temp;
	}
	while (current_label != NULL)
	{
		temp_label = current_label->next;
		free(current_label);
		current_label = temp_label;
	}
}

void			free_all(t_asm *asm_parsing)
{
	free_list(asm_parsing);
	ft_strdel(&asm_parsing->filename);
	ft_strdel(&asm_parsing->byte_code);
	free(asm_parsing);
}

int				check_for_disasm(char const *argv[])
{
	if (ft_strequ(argv[1], "-d"))
		return (1);
	return (0);
}
