/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:56:34 by ifran             #+#    #+#             */
/*   Updated: 2019/09/11 14:06:17 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	if (size < dst_len)
		return (ft_strlen(src) + size);
	while (dst[i])
		++i;
	while (*src && (i + 1 < size))
	{
		dst[i] = *src++;
		++i;
	}
	dst[i] = '\0';
	return (i + ft_strlen(src));
}
