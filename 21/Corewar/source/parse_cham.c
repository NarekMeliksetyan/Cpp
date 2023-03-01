/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:06:38 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:49:22 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int					vm_code_size(int fd)
{
	t_conv			size;
	int				i;
	int				temp;

	temp = 0;
	i = -1;
	while (++i < 4)
		temp += read(fd, &size.bytes[3 - i], 1);
	if (size.integer > CHAMP_MAX_SIZE)
		ft_error_exit(ERROR_GIGA_CHAMP);
	return (size.integer);
}

void				vm_read_com(int fd, char *comment)
{
	int				i;
	int				temp;

	temp = 0;
	i = -1;
	while (++i < COMMENT_LENGTH)
		temp += read(fd, &comment[i], 1);
	if (temp != COMMENT_LENGTH)
		ft_error_exit(ERROR_FILE_CHAMP);
}

void				vm_parse_name(int fd, char *name)
{
	int				i;
	int				temp;

	i = -1;
	temp = 0;
	while (++i < PROG_NAME_LENGTH)
		temp += read(fd, &name[i], 1);
	if (temp != PROG_NAME_LENGTH)
		ft_error_exit(ERROR_FILE_CHAMP);
}

int					parse_magic_header(int fd)
{
	int				i;
	t_conv			header;
	unsigned char	buff;

	header.integer = COREWAR_EXEC_MAGIC;
	i = -1;
	while (++i < 4)
	{
		read(fd, &buff, 1);
		if (buff != header.bytes[3 - i])
			return (0);
	}
	return (1);
}

int					vm_parse_null(int fd)
{
	int				i;
	int				temp;
	unsigned int	buff;

	i = -1;
	temp = read(fd, &buff, 4);
	if (temp != 4 || buff != 0)
		return (0);
	return (1);
}
