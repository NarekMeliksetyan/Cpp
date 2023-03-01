/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:55:34 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 18:55:35 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double base, double exp)
{
	double	i;
	double	res;

	i = 0;
	res = 1;
	while (i < exp)
	{
		res = res * base;
		i++;
	}
	return (res);
}
