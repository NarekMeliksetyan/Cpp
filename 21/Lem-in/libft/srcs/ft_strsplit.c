/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 02:13:15 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 19:24:01 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			word_len(char const *str, char c)
{
	int len;

	len = 0;
	while (*str && *str != c)
	{
		++len;
		++str;
	}
	return (len);
}

static int			count_words(char const *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			++str;
		if (*str)
			++count;
		while (*str && *str != c)
			++str;
	}
	return (count);
}

static char const	*clearing(char const *str, char c)
{
	while (*str && *str == c)
		++str;
	return ((const char *)(str));
}

static char			**strpush(char **arr, char const *str, char c)
{
	int		i;
	int		j;

	i = 0;
	while (*str && count_words(str, c))
	{
		j = 0;
		str = clearing(str, c);
		arr[i] = (char *)malloc(sizeof(char) * (word_len(str, c) + 1));
		if (!(arr[i]))
		{
			ft_freep(arr, i);
			return (NULL);
		}
		while (*str && *str != c)
			arr[i][j++] = *str++;
		arr[i][j] = '\0';
		++i;
	}
	return (arr);
}

char				**ft_strsplit(char const *str, char c)
{
	char	**arr;
	char	**start;
	int		words_num;

	if (!str)
		return (NULL);
	words_num = count_words(str, c);
	arr = (char **)malloc(sizeof(char *) * (words_num + 1));
	if (!arr)
		return (NULL);
	start = arr;
	arr = strpush(arr, str, c);
	arr[words_num] = NULL;
	return (start);
}
