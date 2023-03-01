/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:03:01 by exam              #+#    #+#             */
/*   Updated: 2019/12/07 14:03:38 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define OSIZE 32

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	if (str && *str)
		write(1, str, ft_strlen(str));
}

int		invalid(char *str)
{
	int	i;

	i = 0;
	while (str[++i])
		if (str[i] < 'a' || str[i] > 'z')
			return (1);
	return (0);
}

int		need_help(char *str)
{
	int	i;

	i = 0;
	while (str[++i])
		if (str[i] == 'h')
			return (1);
	return (0);
}

int		geti(char c)
{
	int	i;

	i = 31 - c + 'a';
	return (i);
}

void	options(int ac, char **av)
{
	int	i;
	int	j;
	char	opt[OSIZE + 1];

	i = 0;
	while (i < OSIZE)
		opt[i++] = '0';
	opt[i] = '\0';
	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j] != '-')
			continue ;
		if (invalid(av[i]))
			return (ft_putstr("Invalid Option"));
		if (need_help(av[i]))
			return (ft_putstr("options: abcdefghijklmnopqrstuvwxyz"));
		while (av[i][++j])
			opt[geti(av[i][j])] = '1';
	}
	i = 0;
	while (i < OSIZE)
	{
		if (i)
			write(1, " ", 1);
		write(1, &opt[i], 8);
		i += 8;
	}
}

int main(int argc, char **argv)
{
	if (argc < 2 || !**argv)
		ft_putstr("options: abcdefghijklmnopqrstuvwxyz");
	else
		options(argc, argv);
	write(1, "\n", 1);
	return (0);
}
