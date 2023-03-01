/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:08:47 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 18:08:52 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmap_free(t_list *first)
{
	if (first == NULL)
		return (NULL);
	ft_lstdel(&first, &ft_lstdel_content);
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *tmp;
	t_list *last;

	last = NULL;
	first = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (tmp == NULL)
			return (ft_lstmap_free(first));
		if (last)
			last->next = tmp;
		else
			first = tmp;
		last = tmp;
		lst = lst->next;
	}
	return (first);
}
