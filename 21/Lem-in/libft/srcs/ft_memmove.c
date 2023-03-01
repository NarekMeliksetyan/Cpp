/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:46:01 by ifran             #+#    #+#             */
/*   Updated: 2019/09/11 18:46:11 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *cdst;
	char *csrc;

	csrc = (char *)src;
	cdst = (char *)dst;
	if (!csrc && !cdst)
		return (NULL);
	if (csrc >= cdst)
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	else
	{
		while (len > 0)
		{
			--len;
			cdst[len] = csrc[len];
		}
	}
	return (dst);
}
