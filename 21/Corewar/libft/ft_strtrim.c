/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:10:05 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:21:25 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (is_whitespace(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && is_whitespace(s[end]))
		end--;
	if (end < start)
		return (res = ft_strdup(""));
	res = ft_strsub(s, start, end - start + 1);
	return (res);
}
