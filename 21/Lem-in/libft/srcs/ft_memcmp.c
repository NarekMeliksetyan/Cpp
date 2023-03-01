/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 04:03:45 by ifran             #+#    #+#             */
/*   Updated: 2019/09/12 16:04:39 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	char	*cs1;
	unsigned	char	*cs2;

	if ((!s1 && !s2) || !n)
		return (0);
	cs1 = (unsigned char *)(s1);
	cs2 = (unsigned char *)(s2);
	while (n--)
	{
		if (*cs1 != *cs2)
			return ((int)(*cs1 - *cs2));
		++cs1;
		++cs2;
	}
	return (0);
}
