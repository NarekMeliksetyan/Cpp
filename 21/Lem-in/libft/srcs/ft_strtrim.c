/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:41:10 by ifran             #+#    #+#             */
/*   Updated: 2019/11/30 13:29:18 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		str_len(const char *str)
{
	int len;

	len = 0;
	if (!(*str))
		return (0);
	while (*str)
	{
		++str;
		++len;
	}
	--str;
	while (*str == '\t' || *str == '\n' || *str == ' ')
	{
		--str;
		--len;
	}
	return (len);
}

char					*ft_strtrim(char const *s)
{
	char			*start;
	char			*arr;
	unsigned int	len;

	if (!s)
		return (NULL);
	while (ft_isspace(*s))
		s++;
	len = str_len(s);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	start = arr;
	while (len)
	{
		*arr++ = *s++;
		--len;
	}
	*arr = '\0';
	return (start);
}
