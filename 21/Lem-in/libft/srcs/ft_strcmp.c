/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:09:32 by ifran             #+#    #+#             */
/*   Updated: 2019/09/12 15:48:05 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0' || *s2 == '\0')
			return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
		++s1;
		++s2;
	}
	return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
}
