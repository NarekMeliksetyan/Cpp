/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:04:41 by ifran             #+#    #+#             */
/*   Updated: 2019/09/10 18:05:07 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n == 0)
		ft_putchar('0');
	return (n);
}

void			ft_putnbr(int n)
{
	int		i;
	char	arr[11];

	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		ft_putchar('8');
		return ;
	}
	i = -1;
	n = check(n);
	while (n > 0)
	{
		arr[++i] = '0' + (n % 10);
		n /= 10;
	}
	while (i >= 0)
		ft_putchar(arr[i--]);
}
