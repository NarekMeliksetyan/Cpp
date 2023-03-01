/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:06:15 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/04 13:06:43 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	len;
	int	counter;
	int	*array;

	if (min >= max)
		return (0);
	array = malloc(sizeof(int) * (max - min));
	if (!array)
		return (0);
	len = 0;
	counter = min;
	while (len < max - min)
		array[len++] = counter++;
	return (array);
}
