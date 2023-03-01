/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:00:42 by jkrypto           #+#    #+#             */
/*   Updated: 2020/03/14 15:52:08 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error(int err)
{
	if (err == 1)
		ft_putendl_fd("\e[31mERROR\e[0m", 2);
	else if (err == 2)
		ft_putendl_fd("\e[31mERROR: no such file\e[0m", 2);
	else if (err == 3)
		ft_putendl_fd("\e[31mERROR: room's duplicate\e[0m", 2);
	else if (err == 4)
		ft_putendl_fd("\e[31mERROR: link's duplicate\e[0m", 2);
	else if (err == 5)
		ft_putendl_fd("\e[31mERROR: no start/end room\e[0m", 2);
	else if (err == 6)
		ft_putendl_fd("\e[31mERROR: no path\e[0m", 2);
	else if (err == 7)
		ft_putendl_fd("\e[31mERROR: too many arguments\e[0m", 2);
	exit(err);
}
