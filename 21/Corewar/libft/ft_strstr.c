/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:25:55 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:21:25 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		pos;
	char	*dst;
	int		i;
	int		j;

	pos = 0;
	dst = (char *)haystack;
	while (dst[pos])
	{
		j = 0;
		i = pos;
		while (needle[j] == dst[i] && needle[j])
		{
			j++;
			i++;
		}
		if (!needle[j])
			return (&dst[pos]);
		pos++;
	}
	if (*dst == '\0' && *needle == '\0')
		return (&dst[pos]);
	return (0);
}
