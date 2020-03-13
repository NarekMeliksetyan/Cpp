/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:28:32 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/18 22:23:46 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	getlen(char *s, long *len1, long *len2)
{
	long	i;
	long	j;
	long	k;
	long	res;

	i = 0;
	j = 0;
	k = 0;
	while (ft_isspace(s[i]))
		i++;
	while (s[j])
		j++;
	res = j;
	while (ft_isspace(s[j - 1]))
	{
		j--;
		k++;
	}
	res = res - i - k;
	if (res > 0)
		*len1 = res;
	else
		*len1 = 1;
	*len2 = k;
}

char		*ft_strtrim(char const *s)
{
	long	i;
	long	j;
	long	len1;
	long	len2;
	char	*res;

	if (!s)
		return (0);
	getlen((char*)s, &len1, &len2);
	res = (char*)malloc(sizeof(char) * (len1 + 1));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[i + len2])
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
