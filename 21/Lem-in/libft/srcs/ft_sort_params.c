/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:07:12 by ifran             #+#    #+#             */
/*   Updated: 2019/09/12 22:42:04 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_params(int argc, char **argv)
{
	int		i;
	int		count;
	char	*temp;
	char	**start;

	start = argv;
	count = 1;
	while (count < argc)
	{
		i = count + 1;
		while (i < argc)
		{
			if (ft_strcmp(argv[count], argv[i]))
			{
				temp = argv[count];
				argv[count] = argv[i];
				argv[i] = temp;
			}
			++i;
		}
		++count;
	}
	return (start);
}
