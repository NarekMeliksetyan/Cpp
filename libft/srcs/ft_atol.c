/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:38:26 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/27 20:38:45 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atol(const char *str)
{
	int		sgn;
	size_t	nbr;

	nbr = 0;
	sgn = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
		sgn = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (size_t)(nbr * 10 + *str++ - '0');
		if (nbr > MAX_LONG && sgn == 1)
			return (-1);
		if (nbr > MAX_LONG && sgn == -1)
			return (0);
	}
	return ((long)(nbr * sgn));
}
