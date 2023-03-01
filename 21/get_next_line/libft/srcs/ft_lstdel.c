/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:08:10 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/15 18:08:22 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;
	t_list	*temp;

	list = *alst;
	while (list)
	{
		temp = list->next;
		(*del)(list->content, list->content_size);
		free(list);
		list = temp;
	}
	*alst = NULL;
}
