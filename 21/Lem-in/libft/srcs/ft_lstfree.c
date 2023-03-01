/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:56:00 by ifran             #+#    #+#             */
/*   Updated: 2019/09/12 22:45:33 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstfree(t_list **list)
{
	t_list *temp;

	while ((*list)->next)
	{
		temp = (*list)->next;
		free((*list)->content);
		(*list)->content = NULL;
		free(*list);
		*list = NULL;
		*list = temp;
	}
	free((*list)->content);
	(*list)->content = NULL;
	free(*list);
	*list = NULL;
}
