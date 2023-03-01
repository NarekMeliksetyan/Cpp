/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 01:58:14 by ifran             #+#    #+#             */
/*   Updated: 2019/10/12 08:57:51 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	char	*arr_start;

	if (!s || !(len + 1))
		return (NULL);
	while (start)
	{
		++s;
		--start;
	}
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arr_start = arr;
	while (len)
	{
		*arr++ = *s++;
		--len;
	}
	*arr = '\0';
	return (arr_start);
}
