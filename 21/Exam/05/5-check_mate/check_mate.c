/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:08:06 by exam              #+#    #+#             */
/*   Updated: 2019/10/24 15:57:26 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putres(int res)
{
	if (res == 0)
		write(1, "Fail", 4);
	else if (res == 1)
		write(1, "Success", 7);
}

int		ft_ispiece(char c)
{
	if (c == 'P' || c == 'B' || c == 'R' || c == 'Q' || c == 'K')
		return (c);
	else
		return (0);
}

int		ft_strlen(char *str)
{
	int l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

int		check_board(char **board, int size)
{
	int	i;
	int j;
	int k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		j = ft_strlen(board[i]);
		if (j != size)
		{
			ft_putres(0);
			return (0);
		}
	}
	i = -1;
	j = -1;
	while (++i < size)
	{
		while (++j < size)
			if (board[i][j] == 'K')
				k++;
		j = -1;
	}
	if (k == 1)
		return (1);
	ft_putres(0);
	return (0);
}

void	fix_board(char ***board, int size)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < size)
	{
		while (++j < size)
			if (!ft_ispiece((*board)[i][j]))
				(*board)[i][j] = '.';
		j = -1;
	}
}

int		solve_p(int ik, int jk, int ip, int jp)
{
	if ((ik == ip - 1) && (jk == jp + 1 || jk == jp - 1))
		return (1);
	return (0);
}

int		solve_r(char **board, int ik, int jk, int ir, int jr)
{
	int i;
	int j;
	int ni;
	int nj;

	i = ik < ir ? ik : ir;
	j = jk < jr ? jk : jr;
	ni = ik > ir ? ik : ir;
	nj = jk > jr ? jk : jr;
	if (ik == ir)
	{
		while (++j < nj)
			if (board[ik][j] != '.')
				return (0);
		return (1);
	}
	else if (jk == jr)
	{
		while (++i < ni)
			if (board[i][jk] != '.')
				return (0);
		return (1);
	}
	return (0);
}

int		solve_b(char **board, int ik, int jk, int ib, int jb)
{
	int i;
	int j;
	int ni;
	int nj;

	i = ik < ib ? ik : ib;
	j = jk < jb ? jk : jb;
	ni = ik > ib ? ik : ib;
	nj = jk > jb ? jk : jb;
	if (ik - jk == ib - jb)
	{
		while (++i < ni && ++j < nj)
			if (board[i][j] != '.')
				return (0);
		return (1);
	}
	else if (ik + jk == ib + jb)
	{
		while (++i < ni && --nj > j)
			if (board[i][nj] != '.')
				return (0);
		return (1);
	}
	return (0);
}

int		solve_q(char **board, int ik, int jk, int iq, int jq)
{
	return (solve_b(board, ik, jk, iq, jq)
			|| solve_r(board, ik, jk, iq, jq));
}

void	solve_k(char **board, int size, int ik, int jk)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < size)
	{
		while (++j < size)
		{
			if (board[i][j] == 'P')
				if (solve_p(ik, jk, i, j))
					return (ft_putres(1));
			if (board[i][j] == 'B')
				if (solve_b(board, ik, jk, i, j))
					return (ft_putres(1));
			if (board[i][j] == 'R')
				if (solve_r(board, ik, jk, i, j))
					return (ft_putres(1));
			if (board[i][j] == 'Q')
				if (solve_q(board, ik, jk, i, j))
					return (ft_putres(1));
		}
		j = -1;
	}
	return (ft_putres(0));

}

void	check_mate(char **board, int size)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (!check_board(board, size))
		return ;
	fix_board(&board, size);
	while (++i < size)
	{
		while (++j < size)
			if (board[i][j] == 'K')
				return (solve_k(board, size, i, j));
		j = -1;
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		check_mate(argv + 1, argc - 1);
	write(1, "\n", 1);
	return (0);
}
