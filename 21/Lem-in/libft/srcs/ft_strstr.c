/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:56:57 by ifran             #+#    #+#             */
/*   Updated: 2019/09/11 13:27:08 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	h;

	h = 0;
	if (!(*needle))
		return ((char *)(haystack));
	while (haystack[h])
	{
		i = 0;
		while (haystack[h] && needle[i] && haystack[h] == needle[i])
		{
			i++;
			h++;
		}
		if (!(needle[i]))
			return ((char *)(haystack + (h - i)));
		h -= i - 1;
	}
	return (NULL);
}
