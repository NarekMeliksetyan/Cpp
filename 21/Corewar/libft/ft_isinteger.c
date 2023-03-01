/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:00:27 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:22:04 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinteger(char *line)
{
	int		num;
	char	*itoa;
	int		res;

	num = ft_atoi(line);
	itoa = ft_itoa(num);
	if (ft_strequ(itoa, line))
		res = 1;
	else
		res = 0;
	ft_strdel(&itoa);
	return (res);
}
