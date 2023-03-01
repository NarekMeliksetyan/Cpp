/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:45:41 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:21:25 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	pos;
	char			*res;

	res = (char *)haystack;
	pos = 0;
	while (pos < len && res[pos])
	{
		j = 0;
		i = pos;
		while (i < len && res[i] == needle[j] && needle[j])
		{
			i++;
			j++;
		}
		if (!needle[j])
			return (&res[pos]);
		pos++;
	}
	if (*haystack == '\0' && *needle == '\0')
		return (&res[pos]);
	return (0);
}
