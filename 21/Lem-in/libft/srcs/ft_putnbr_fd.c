/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:47:30 by ifran             #+#    #+#             */
/*   Updated: 2019/09/10 18:09:24 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	return (n);
}

void			ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	arr[11];

	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('8', fd);
		return ;
	}
	i = -1;
	n = check(n, fd);
	while (n > 0)
	{
		arr[++i] = '0' + (n % 10);
		n /= 10;
	}
	while (i >= 0)
		ft_putchar_fd(arr[i--], fd);
}
