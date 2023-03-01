/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:57:47 by ifran             #+#    #+#             */
/*   Updated: 2019/09/10 18:13:20 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_len(int n)
{
	int len;

	len = 1;
	if (n < 0)
	{
		++len;
		n *= -1;
	}
	while (n >= 10)
	{
		++len;
		n /= 10;
	}
	return (len);
}

static char		*swap_num(char *str)
{
	int		i;
	char	temp;
	int		len;
	char	*start;

	start = str;
	len = ft_strlen(str) - 1;
	i = ((*str == '-') ? 1 : 0);
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		++i;
		--len;
	}
	return (start);
}

char			*ft_itoa(int n)
{
	char	*start;
	char	*arr;
	int		len;

	len = num_len(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	start = arr;
	if (n == -2147483648)
		return (ft_strcpy(start, "-2147483648"));
	if (n < 0)
	{
		n *= -1;
		*arr++ = '-';
		--len;
	}
	while (len--)
	{
		*arr++ = '0' + n % 10;
		n /= 10;
	}
	*arr = '\0';
	start = swap_num(start);
	return (start);
}
