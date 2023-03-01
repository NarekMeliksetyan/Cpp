/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:06:32 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 21:06:33 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char*)haystack);
	while ((i + 1) <= len && haystack[i] != '\0')
	{
		if (i + needle_len > len)
			return (NULL);
		if (ft_strncmp(needle, &haystack[i], needle_len) == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
