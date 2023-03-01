/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:54:47 by ifran             #+#    #+#             */
/*   Updated: 2019/09/11 15:21:26 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	nb;
	unsigned long int	backup;

	backup = 0;
	nb = 0;
	sign = 1;
	str = ft_clearing(str);
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while ((*str >= '0') && (*str <= '9'))
	{
		nb = 10 * nb + (*str - '0');
		if (nb < backup)
			return ((sign == 1) ? -1 : 0);
		backup = nb;
		++str;
	}
	return (sign * (int)(nb));
}
