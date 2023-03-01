/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:08:05 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:21:25 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst2;
	t_list *lst2_temp;

	if (!lst || !f)
		return (NULL);
	lst2 = f(ft_lstnew(lst->content, lst->content_size));
	lst = lst->next;
	lst2_temp = lst2;
	while (lst)
	{
		lst2_temp->next = f(ft_lstnew(lst->content, lst->content_size));
		lst2_temp = lst2_temp->next;
		lst = lst->next;
	}
	return (lst2);
}
