/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:03:26 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 21:03:51 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	size_t	len;
	char	*buf;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	buf = (char*)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	while (s[i])
	{
		buf[i] = (*f)(s[i]);
		i++;
	}
	buf[i] = 0;
	return (buf);
}
