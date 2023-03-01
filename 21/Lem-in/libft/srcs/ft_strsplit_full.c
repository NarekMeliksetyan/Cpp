/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_full.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 02:13:15 by ifran             #+#    #+#             */
/*   Updated: 2019/11/07 20:40:58 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_space(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\r')
			|| (c == '\n') || (c == '\v') || (c == '\f'))
		return (1);
	return (0);
}

static int			word_len(char const *str)
{
	int len;

	len = 0;
	while (*str && !is_space(*str))
	{
		++len;
		++str;
	}
	return (len);
}

static int			count_words(char const *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			++str;
		if (*str)
			++count;
		while (*str && !is_space(*str))
			++str;
	}
	return (count);
}

static char			**strpush(char **arr, char const *str)
{
	int		i;
	int		j;

	i = 0;
	while (*str && count_words(str))
	{
		j = 0;
		while (is_space(*str))
			++str;
		arr[i] = (char *)malloc(sizeof(char) * (word_len(str) + 1));
		if (!(arr[i]))
		{
			ft_freep(arr, i);
			return (NULL);
		}
		while (*str && !is_space(*str))
			arr[i][j++] = *str++;
		arr[i][j] = '\0';
		++i;
	}
	return (arr);
}

char				**ft_strsplit_full(char const *str)
{
	char	**arr;
	char	**start;
	int		words_num;

	if (!str)
		return (NULL);
	words_num = count_words(str);
	arr = (char **)malloc(sizeof(char *) * (words_num + 1));
	if (!arr)
		return (NULL);
	start = arr;
	arr = strpush(arr, str);
	arr[words_num] = NULL;
	return (start);
}
