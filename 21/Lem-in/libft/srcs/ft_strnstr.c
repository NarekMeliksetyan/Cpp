/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 03:05:25 by ifran             #+#    #+#             */
/*   Updated: 2019/09/11 13:32:36 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	h;

	h = 0;
	if (!(*needle))
		return ((char *)(haystack));
	while (haystack[h] && len)
	{
		i = 0;
		while (haystack[h] && len && needle[i] && haystack[h] == needle[i])
		{
			i++;
			h++;
			--len;
		}
		if (!(needle[i]))
			return ((char *)(haystack + (h - i)));
		len += i - 1;
		h -= i - 1;
	}
	return (NULL);
}
