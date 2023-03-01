/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:01:25 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 21:01:30 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;

	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s1) + 1));
	if (dest)
		dest = ft_strcpy(dest, s1);
	else
		dest = ((void *)0);
	return (dest);
}
