/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:53:26 by jkrypto           #+#    #+#             */
/*   Updated: 2020/03/04 18:53:29 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t size, long dif)
{
	void	*res;

	res = ft_memalloc(size + dif);
	if (src && res)
	{
		ft_memcpy(res, src, size);
		if (dif > 0)
			ft_bzero(res + size, dif);
		ft_memdel(&src);
	}
	return (res);
}
