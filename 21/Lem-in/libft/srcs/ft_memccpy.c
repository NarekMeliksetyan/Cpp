/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 04:07:58 by ifran             #+#    #+#             */
/*   Updated: 2019/09/11 16:31:54 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	i = 0;
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (n)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == (unsigned char)(c))
			return (dst + i + 1);
		++i;
		--n;
	}
	return (NULL);
}
