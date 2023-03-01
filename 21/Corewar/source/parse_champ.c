/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:02:31 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/18 11:48:55 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void				read_exec_code(int fd, t_champ *champion, t_vm *vm)
{
	int				mem;
	unsigned int	i;

	mem = (champion->number - 1) * (MEM_SIZE / vm->count_champ);
	i = 0;
	while (read(fd, &vm->map[mem + i]->value, 1))
	{
		vm->map[mem + i]->color = champion->number - 1 + 1;
		i++;
	}
	if (i != champion->header->prog_size)
		ft_error_exit(ERROR_CODE_SIZE);
}

t_bool				is_champ(char *name)
{
	char			*extention;
	t_bool			temp;

	extention = ft_strsub(name, ft_strlen(name) - 4, 4);
	if (ft_strlen(name) > 4 && ft_strequ(extention, ".cor"))
		temp = true;
	else
		temp = false;
	ft_strdel(&extention);
	return (temp);
}

t_champ				*new_champ(char *file_name)
{
	t_champ			*champ;

	if (!(champ = ft_memalloc(sizeof(t_champ))))
		ft_error_exit(ERROR_MEMORY_ALLOCATED);
	champ->file = file_name;
	return (champ);
}

t_champ				*find_champ(int n, t_vm *vm)
{
	int				i;

	i = -1;
	while (++i < 4 && vm->champs[i])
	{
		if (vm->champs[i]->number == -n)
			return (vm->champs[i]);
	}
	return (NULL);
}

void				parse_champs(t_vm *vm)
{
	int				fd;
	int				i;

	i = -1;
	while (vm->champs[++i] != NULL)
	{
		if (!(vm->champs[i]->header = ft_memalloc(sizeof(t_header))))
			ft_error_exit(ERROR_MEMORY_ALLOCATED);
		if ((fd = open(vm->champs[i]->file, O_RDONLY)) == -1)
			ft_error_exit(ERROR_OPEN);
		if (!parse_magic_header(fd))
			ft_error_exit(ERROR_HEADER);
		vm_parse_name(fd, vm->champs[i]->header->prog_name);
		if (!vm_parse_null(fd))
			ft_error_exit(ERROR_COMMENT_NULL);
		vm->champs[i]->header->prog_size = vm_code_size(fd);
		vm_read_com(fd, vm->champs[i]->header->comment);
		if (!vm_parse_null(fd))
			ft_error_exit(ERROR_COMMENT_NULL);
		read_exec_code(fd, vm->champs[i], vm);
		if (vm->champs[i]->number == vm->count_champ)
			vm->last_live = vm->champs[i];
		close(fd);
	}
}
