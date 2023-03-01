/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:54:17 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 18:54:18 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	tmpc;

	i = 0;
	tmp = (unsigned char*)s;
	tmpc = (unsigned char)c;
	while (n > 0)
	{
		if (tmp[i] == tmpc)
			return ((void*)&s[i]);
		i++;
		n--;
	}
	return (NULL);
}
