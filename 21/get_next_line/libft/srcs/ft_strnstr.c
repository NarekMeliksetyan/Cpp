/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:31:50 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/08 21:32:52 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int i;
	unsigned int pos;

	if (!*to_find)
		return ((char*)str);
	pos = 0;
	while (str[pos] && (size_t)pos < len)
	{
		if (str[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] && str[pos + i] == to_find[i] &&
					(size_t)(pos + i) < len)
				i++;
			if (to_find[i] == '\0')
				return ((char*)&str[pos]);
		}
		pos++;
	}
	return (0);
}
