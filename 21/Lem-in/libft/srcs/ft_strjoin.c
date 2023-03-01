/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 01:31:43 by ifran             #+#    #+#             */
/*   Updated: 2019/09/11 14:22:12 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*arr;
	char			*start;
	unsigned int	full_len;

	if (!s1 || !s2)
		return (NULL);
	full_len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (full_len + 1));
	if (!arr)
		return (NULL);
	start = arr;
	while (*s1)
		*arr++ = *s1++;
	while (*s2)
		*arr++ = *s2++;
	*arr = '\0';
	return (start);
}
