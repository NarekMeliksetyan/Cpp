/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:07:52 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 21:08:05 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *buf;

	if (len + 1 == 0)
		return (NULL);
	if (s == NULL || &s[start] == NULL)
		return (NULL);
	buf = (char*)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	ft_strncpy(buf, &s[start], len);
	buf[len] = 0;
	return (buf);
}
