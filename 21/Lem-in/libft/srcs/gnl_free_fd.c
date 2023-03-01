/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_free_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:54:47 by jkrypto           #+#    #+#             */
/*   Updated: 2020/03/04 18:54:48 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		gnl_free_fd(t_file **file, int fd)
{
	t_file	*temp;
	t_file	*to_free;

	if ((*file)->fd == fd)
	{
		temp = *file;
		*file = (*file)->next;
		free(temp);
	}
	else
	{
		temp = *file;
		while (temp->next->fd != fd)
			temp = temp->next;
		to_free = temp->next;
		temp->next = to_free->next;
		free(to_free);
	}
}
