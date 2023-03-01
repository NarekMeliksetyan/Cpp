/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:00:11 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/04 13:00:41 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);
void	ft_sort_params(int argc, char *argv[]);
void	ft_print_params(int argc, char *argv[]);

int		main(int argc, char *argv[])
{
	ft_sort_params(argc, argv);
	ft_print_params(argc, argv);
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(int argc, char *argv[])
{
	int i;

	i = 0;
	while (i < (argc - 1))
	{
		i++;
		if (i < (argc - 1) && ft_strcmp(argv[i + 1], argv[i]) < 0)
		{
			argv[argc + 1] = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = argv[argc + 1];
			i = 0;
		}
	}
}

void	ft_print_params(int argc, char *argv[])
{
	int i;
	int j;

	i = 0;
	while (i++ < argc - 1)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
	}
}
