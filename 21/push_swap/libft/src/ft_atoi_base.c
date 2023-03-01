/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:56:17 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 17:56:19 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_char_to_int(char c, int base)
{
	if (c >= 'a' && c <= 'z' && c - 'a' + 10 < base)
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'Z' && c - 'A' + 10 < base)
		return (c - 'A' + 10);
	else if (ft_isdigit(c) && c - '0' < base)
		return (c - '0');
	else
		return (-1);
}

int				ft_atoi_base(const char *str, int base)
{
	int num;
	int i;
	int step;

	num = 0;
	step = 0;
	i = ft_skipspace(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != 0 && ft_char_to_int(str[i], base) >= 0)
		i++;
	i--;
	while (str[i] && ft_char_to_int(str[i], base) >= 0)
	{
		num = num + ft_char_to_int(str[i], base) * ft_pow(base, step);
		if (num < 0)
			return (0);
		i--;
		step++;
	}
	return (str[i] == '-' ? -num : num);
}
