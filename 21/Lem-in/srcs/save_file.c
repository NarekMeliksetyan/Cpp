/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:04:17 by jkrypto           #+#    #+#             */
/*   Updated: 2020/03/04 19:04:21 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	save_str(t_lemin *lemin, char *str)
{
	t_strings *file;

	if (!(file = (t_strings *)malloc(sizeof(t_strings))))
		error(1);
	file->str = str;
	file->next = NULL;
	if (lemin->file_end)
		lemin->file_end->next = file;
	else
		lemin->file = file;
	lemin->file_end = file;
}
