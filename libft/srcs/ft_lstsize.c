/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 22:19:20 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/16 22:32:26 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *begin_list)
{
	size_t	size;
	t_list	*temp;

	size = 0;
	if (!begin_list)
		return (size);
	temp = begin_list;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
