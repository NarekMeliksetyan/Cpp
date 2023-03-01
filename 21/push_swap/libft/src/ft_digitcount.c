/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:57:57 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 17:57:58 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitcount(long long int number)
{
	int count;

	count = (number == 0) ? 1 : 0;
	while (number != 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}
