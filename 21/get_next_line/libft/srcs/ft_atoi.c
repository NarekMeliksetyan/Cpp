/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:36:44 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/10 19:40:58 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				sign;
	unsigned long	nbr;

	nbr = 0;
	sign = 1;
	while (*str == '\n' || *str == '\t'
			|| *str == '\r' || *str == '\f' || *str == '\v'
			|| *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (unsigned long long)(nbr * 10 + *str++ - '0');
		if (nbr > MAX_LONG && sign == 1)
			return (-1);
		if (nbr > MAX_LONG && sign == -1)
			return (0);
	}
	return ((int)(nbr * sign));
}
