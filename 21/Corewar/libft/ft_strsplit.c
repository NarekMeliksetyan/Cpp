/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:00:07 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:21:25 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s, char c)
{
	size_t	i;
	int		words;
	int		flag;

	i = 0;
	words = 0;
	while (s[i])
	{
		flag = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			flag = 1;
		}
		if (flag)
			words += 1;
	}
	return (words);
}

static int		length_word(const char *s, char c, size_t i)
{
	size_t len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void		ft_arrclr(char **res)
{
	int i;

	if (!res)
		return ;
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s || !(res = (char **)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	res[count_words(s, c)] = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(res[j] = ft_strsub(s, i, length_word(s, c, i))))
			{
				ft_arrclr(res);
				return (NULL);
			}
			i += length_word(s, c, i);
			j++;
		}
		else
			i++;
	}
	return (res);
}
