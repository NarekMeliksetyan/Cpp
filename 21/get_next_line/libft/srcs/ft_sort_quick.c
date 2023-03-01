/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:56:10 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/17 15:01:14 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_partition(int *arr, int low, int high)
{
	int i;
	int j;
	int pivot;

	i = low;
	j = low;
	pivot = arr[high];
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			ft_swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	ft_swap(&arr[i], &arr[high]);
	return (i);
}

void		ft_sort_quick(int *arr, int low, int high)
{
	int	m;

	if (low < high)
	{
		m = ft_partition(arr, low, high);
		ft_sort_quick(arr, low, m - 1);
		ft_sort_quick(arr, m + 1, high);
	}
}
