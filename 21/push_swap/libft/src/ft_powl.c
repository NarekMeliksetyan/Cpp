/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:55:51 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 18:55:52 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_powl(long double base, long double exp)
{
	long double	i;
	long double	res;

	i = 0;
	res = 1;
	while (i < exp)
	{
		res = res * base;
		i++;
	}
	return (res);
}
