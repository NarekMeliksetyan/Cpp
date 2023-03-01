/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:34:30 by ifran             #+#    #+#             */
/*   Updated: 2019/09/12 16:57:28 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;
	void		*mcontent;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		mcontent = malloc(sizeof(size_t) * content_size);
		if (!mcontent)
		{
			free(list);
			return (NULL);
		}
		ft_memcpy(mcontent, content, content_size);
		list->content = mcontent;
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
