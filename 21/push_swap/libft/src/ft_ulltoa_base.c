/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:09:53 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 21:09:53 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long int val, int base)
{
	int		i;
	char	*nbr;

	i = 1;
	while (ft_pow(base, i) - 1 < val)
		i++;
	nbr = ft_strnew(i);
	while (i-- > 0)
	{
		nbr[i] = (val % base) + (val % base > 9 ? 'A' - 10 : '0');
		val = val / base;
	}
	return (nbr);
}
