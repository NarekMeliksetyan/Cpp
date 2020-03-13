/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:10:52 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/15 18:14:03 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*list;
	t_list	*temp;

	head = (t_list*)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	temp = NULL;
	while (lst)
	{
		list = (t_list*)malloc(sizeof(t_list));
		if (!list)
			return (NULL);
		list = (f)(lst);
		if (temp)
			temp->next = list;
		else
			head = list;
		temp = list;
		lst = lst->next;
	}
	return (head);
}
