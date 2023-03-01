/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:52:26 by ifran             #+#    #+#             */
/*   Updated: 2020/03/05 23:55:12 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 2

typedef struct		s_elem
{
	char			str[BUFF_SIZE + 1];
	struct s_elem	*next;
}					t_elem;

typedef struct		s_file
{
	int				fd;
	size_t			len;
	t_elem			*start;
	t_elem			*end;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
