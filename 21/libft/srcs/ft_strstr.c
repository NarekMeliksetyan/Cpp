/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:09:51 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/22 20:33:32 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	unsigned int i;
	unsigned int pos;

	if (!*to_find)
		return ((char*)str);
	pos = 0;
	while (str[pos])
	{
		if (str[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] && str[pos + i] == to_find[i])
				i++;
			if (to_find[i] == '\0')
				return ((char*)&str[pos]);
		}
		pos++;
	}
	return (0);
}
