/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_of_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:05:00 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:05:03 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_label		*create_label(char *name, int refer)
{
	t_label *new_label;

	new_label = (t_label*)malloc(sizeof(t_label));
	new_label->name = name;
	new_label->refer = refer;
	new_label->next = NULL;
	return (new_label);
}

void		add_label_to_list(t_asm *asm_parsing, t_label *new_label)
{
	t_label *temp;

	if (asm_parsing->labels == NULL)
		asm_parsing->labels = new_label;
	else
	{
		temp = asm_parsing->labels;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_label;
	}
}
