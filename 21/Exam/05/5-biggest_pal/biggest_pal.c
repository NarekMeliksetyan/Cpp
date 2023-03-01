/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:26:03 by exam              #+#    #+#             */
/*   Updated: 2019/09/21 13:22:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putnstr(char *str, int i, int j)
{
	write(1, (str + i), j - i + 1);
}

int		check_pal(char *str, int i, int j)
{
	while (str[i] && i <= j)
	{
		if (str[i] != str[j])
			return (0);
		i++;
		j--;
	}
	return (1);
}

void	biggest_pal(char *str)
{
	int i = 0;
	int j = 0;
	int mi = 0;
	int mj = 0;
	int	len = ft_strlen(str);

	while (str[i])
	{
		j = len;
		while (i <= j)
		{
			if (str[i] == str[j])
			{
				if (mi <= i && mj - mi <= j - i && check_pal(str, i, j))
				{
					mi = i;
					mj = j;
				}
			}
			j--;
		}
		i++;
	}
	ft_putnstr(str, mi, mj);
}
					
int		main(int argc, char **argv)
{
	if (argc == 2)
			biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}
