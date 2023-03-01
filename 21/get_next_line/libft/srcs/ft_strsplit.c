/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:56:34 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/17 14:55:09 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_malloc(char *s, int len)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char*)malloc(sizeof(char) * (len - 1));
	if (!temp)
		return (0);
	while (i < len)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

static void	fill(char **r, char *s, char c)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
		if (s[i - 1] != c)
			r[j++] = ft_malloc(s + (i - len), len);
	}
}

static int	check_word(char const *s, char c)
{
	int i;
	int cnt;
	int flag;

	i = 0;
	cnt = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		if (!flag && s[i] != c)
		{
			cnt++;
			flag = 1;
		}
		i++;
	}
	return (cnt);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		words;

	if (!s)
		return (0);
	words = check_word(s, c);
	r = (char**)malloc(sizeof(char*) * (words + 1));
	if (!r)
		return (0);
	r[words] = 0;
	fill(r, (char*)s, c);
	return (r);
}
