/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_par.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:06:03 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/17 15:57:05 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	get_n_args(int ac, char **av, t_vm *vm, int *i)
{
	int n;

	if (*i >= ac - 1 || !ft_isinteger(av[*i + 1]) ||
		(n = ft_atoi(av[*i + 1])) < 1 || n > MAX_PLAYERS)
		ft_error_exit(ERROR_RANGE);
	if (*i < ac - 2)
	{
		if (!is_champ(av[*i + 2]))
			ft_error_exit(ERROR_FILE_EXTENTION);
		if (vm->count_champ == 4)
			ft_error_exit(ERROR_GIGA_CHAMPS);
		vm->champs[vm->count_champ] = new_champ(av[*i + 2]);
		vm->champs[vm->count_champ]->number = n;
		vm->count_champ += 1;
		*i += 2;
	}
	else
		ft_error_exit(ERROR_CHAMP);
}

void	get_dump(int ac, char **av, t_vm *vm, int *i)
{
	int n;

	if (*i >= ac - 1 || !ft_isinteger(av[*i + 1]) ||
							(n = ft_atoi(av[*i + 1])) < 0)
		ft_error_exit(ERROR_DUMP_NUMBER);
	vm->flag_dump = ft_atoi(av[*i + 1]);
	*i += 1;
}

t_bool	*check_errors(t_vm *vm, int cur)
{
	int		i;
	int		count;
	t_bool	*nums;

	i = -1;
	if (!(nums = ft_memalloc(sizeof(t_bool) * 4)))
		ft_error_exit(ERROR_MEMORY_ALLOCATED);
	count = 0;
	while (++i < cur)
	{
		if (vm->champs[i]->number == 0)
			count++;
		else if (vm->champs[i]->number > cur)
			ft_error_exit(ERROR_N_EXCEEDS);
		else if (nums[vm->champs[i]->number - 1] == true)
			ft_error_exit(ERROR_DUPLICAT);
		else
			nums[vm->champs[i]->number - 1] = true;
	}
	return (nums);
}

void	check_champs_number(t_vm *vm, int cur)
{
	int		i;
	t_bool	*nums;
	int		j;

	if (vm->champs[0] == NULL)
		ft_error_exit(ERROR_NULL_CHAMPS);
	nums = check_errors(vm, cur);
	i = -1;
	while (++i < cur)
	{
		if (vm->champs[i]->number == 0)
		{
			j = 0;
			while (nums[j] != false)
				j++;
			vm->champs[i]->number = j + 1;
			nums[j] = true;
		}
	}
	if (vm->flag_verbose && vm->flag_visual)
		ft_error_exit(ERROR_FLAG_COMBINATION);
	free(nums);
}

void	parse_par(int ac, char **av, t_vm *vm)
{
	int i;

	i = 0;
	if (ac == 1)
		usage();
	while (++i < ac)
	{
		if (ft_strequ(av[i], "-n"))
			get_n_args(ac, av, vm, &i);
		else if (ft_strequ(av[i], "-verbose"))
			vm->flag_verbose = true;
		else if (ft_strequ(av[i], "-visual"))
			vm->flag_visual = true;
		else if (ft_strequ(av[i], "-dump"))
			get_dump(ac, av, vm, &i);
		else if (!is_champ(av[i]))
			usage();
		else
		{
			if (vm->count_champ == 4)
				ft_error_exit(ERROR_GIGA_CHAMPS);
			vm->champs[vm->count_champ++] = new_champ(av[i]);
		}
	}
	check_champs_number(vm, vm->count_champ);
}
