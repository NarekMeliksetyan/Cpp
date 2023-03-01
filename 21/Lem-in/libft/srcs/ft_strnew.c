/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 02:46:58 by ifran             #+#    #+#             */
/*   Updated: 2019/09/10 18:44:39 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*start;
	char	*arr;

	if (size + 1 == 0)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	start = arr;
	while (size)
	{
		*arr++ = '\0';
		--size;
	}
	*arr = '\0';
	return (start);
}
