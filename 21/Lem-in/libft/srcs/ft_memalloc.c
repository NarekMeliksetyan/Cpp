/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:44:26 by ifran             #+#    #+#             */
/*   Updated: 2019/09/10 12:16:32 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *start;
	char *arr;

	arr = (char *)malloc(sizeof(char) * size);
	if (!arr)
		return (NULL);
	start = arr;
	while (size--)
		*arr++ = '\0';
	return ((void *)start);
}
