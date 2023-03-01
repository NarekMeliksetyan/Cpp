/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:52:54 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 18:52:55 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	if (n == 0)
		return (0);
	ns1 = (unsigned char*)s1;
	ns2 = (unsigned char*)s2;
	i = 0;
	while ((i + 1) < n && (ns1[i] == ns2[i]))
	{
		i++;
	}
	return (ns1[i] - ns2[i]);
}
