/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 02:51:57 by ifran             #+#    #+#             */
/*   Updated: 2019/09/10 12:29:06 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *start;

	start = dst;
	while (*src && len)
	{
		*dst++ = *src++;
		--len;
	}
	while (len)
	{
		*dst = '\0';
		++dst;
		--len;
	}
	return (start);
}
