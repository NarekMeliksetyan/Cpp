/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 02:32:56 by ifran             #+#    #+#             */
/*   Updated: 2019/09/11 14:15:24 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*start;
	char			*arr;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	start = arr;
	while (len--)
		*arr++ = (*f)(i++, *s++);
	*arr = '\0';
	return (start);
}
