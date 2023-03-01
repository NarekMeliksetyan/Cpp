/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:05:38 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/27 19:05:39 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	ns1 = (unsigned char*)s1;
	ns2 = (unsigned char*)s2;
	i = 0;
	while ((ns1[i] && ns2[i]) && (ns1[i] == ns2[i]))
		i++;
	return (ns1[i] - ns2[i]);
}
