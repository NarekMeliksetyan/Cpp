/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:48:43 by ifran             #+#    #+#             */
/*   Updated: 2019/10/24 16:34:43 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **lst, t_list *new_list)
{
	t_list *start;

	if (*lst)
	{
		start = *lst;
		while (start->next)
			start = start->next;
		start->next = new_list;
	}
	else
		*lst = new_list;
}
