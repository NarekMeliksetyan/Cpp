/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:01:17 by ifran             #+#    #+#             */
/*   Updated: 2019/10/24 16:33:55 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*tmp;

	if (!lst && !f)
		return (NULL);
	new_list = (f)(lst);
	if (!new_list)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		tmp = (f)(lst);
		if (!tmp)
		{
			ft_lstfree(&new_list);
			return (NULL);
		}
		ft_lstpushback(&new_list, tmp);
		lst = lst->next;
	}
	return (new_list);
}
