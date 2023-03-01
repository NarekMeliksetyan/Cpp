/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:41:34 by ifran             #+#    #+#             */
/*   Updated: 2019/09/12 15:52:56 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && (n > 1))
	{
		if ((*s1 == '\0') || (*s2 == '\0'))
			return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
		--n;
		++s1;
		++s2;
	}
	return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
}
