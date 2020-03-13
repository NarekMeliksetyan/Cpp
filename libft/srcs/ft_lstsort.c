/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:39:26 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/15 18:17:31 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list	*head;
	t_list	*list;
	t_list	*temp;

	head = *begin_list;
	while (head)
	{
		list = *begin_list;
		while (list->next)
		{
			if ((*cmp)(list->content, list->next->content) > 0)
			{
				temp = list->content;
				list->content = list->next->content;
				list->next->content = temp;
			}
			list = list->next;
		}
		head = head->next;
	}
}
