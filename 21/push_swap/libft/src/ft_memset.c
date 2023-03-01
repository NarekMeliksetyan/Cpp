/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:53:54 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 18:53:54 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char*)buf;
	i = 0;
	while (i < count)
	{
		tmp[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}
