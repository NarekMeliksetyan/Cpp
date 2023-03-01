/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_pow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:54:19 by jkrypto           #+#    #+#             */
/*   Updated: 2020/03/04 18:54:29 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned long long	ft_ull_pow(unsigned long long number,
		unsigned long long power)
{
	unsigned long long res;

	res = number;
	while (power > 1)
	{
		res *= number;
		--power;
	}
	return (res);
}
