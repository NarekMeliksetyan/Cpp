/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 02:20:48 by ifran             #+#    #+#             */
/*   Updated: 2019/09/13 01:17:42 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*start;
	char	*arr;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	start = arr;
	while (len)
	{
		*arr++ = (*f)(*s++);
		--len;
	}
	*arr = '\0';
	return (start);
}
