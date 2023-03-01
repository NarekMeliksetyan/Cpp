/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:28:32 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/15 19:06:29 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pure_len(char *s, int *len, int *len2)
{
	int	i;
	int	j;
	int	k;
	int	res;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j])
		j++;
	res = j;
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
	{
		j--;
		k++;
	}
	res = res - i - k;
	if (res > 0)
		*len = res;
	else
		*len = 1;
	*len2 = k;
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len2;
	int		len;
	char	*res;

	if (s == NULL)
		return (0);
	pure_len((char*)s, &len, &len2);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[i + len2])
	{
		res[j] = s[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}
