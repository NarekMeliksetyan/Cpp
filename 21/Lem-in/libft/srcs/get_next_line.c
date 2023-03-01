/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:50:49 by ifran             #+#    #+#             */
/*   Updated: 2020/03/06 08:37:35 by tinkotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			new_elem(t_file *file)
{
	t_elem *new;

	if (!(new = (t_elem *)malloc(sizeof(t_elem))))
		return (0);
	new->next = NULL;
	if (file->end)
		file->end->next = new;
	else
		file->start = new;
	file->end = new;
	return (1);
}

static t_file		*check_struct(t_file **file, int fd)
{
	t_file *temp;

	if (fd < 0)
		return (NULL);
	temp = *file;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	temp->fd = fd;
	temp->len = 0;
	temp->next = *file;
	temp->start = NULL;
	temp->end = NULL;
	*file = temp;
	return (temp);
}

static void			to_line(t_file *file, char **line, size_t t_len)
{
	t_elem	*elem;
	char	*push;
	char	*point;

	push = *line;
	elem = file->start;
	(*line)[file->len - t_len] = '\0';
	while (file->len != t_len)
	{
		point = &((elem->str)[0]);
		while (*point && file->len > t_len)
		{
			*push++ = *point++;
			--(file->len);
		}
		if (!(*point))
		{
			elem = elem->next;
			free(file->start);
			file->start = elem;
		}
	}
	file->len = file->len ? file->len - 1 : 0;
}

static int			push_line(t_file **f, t_file *file, char **line, char *tmp)
{
	size_t	t_len;

	if (!(file->len))
	{
		gnl_free_fd(f, file->fd);
		return (0);
	}
	t_len = tmp ? ft_strlen(tmp) : 0;
	if (!(*line = (char *)malloc(file->len - t_len + 1)))
		return (-1);
	to_line(file, line, t_len);
	if (file->len)
	{
		ft_strcpy(file->start->str, tmp + 1);
		(file->start->str)[t_len - 1] = '\0';
	}
	else
	{
		free(file->end);
		file->start = NULL;
		file->end = NULL;
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_file	*file = NULL;
	t_file			*curr;
	char			*temp;
	int				i;

	if (!(curr = check_struct(&file, fd)))
		return (-1);
	if (curr->len && (temp = ft_strchr(curr->start->str, '\n')))
		return (push_line(&file, curr, line, temp));
	new_elem(curr);
	while ((i = read(fd, curr->end->str, BUFF_SIZE)))
	{
		if (i < 0)
			return (-1);
		(curr->end->str)[i] = '\0';
		file->len += i;
		if ((temp = ft_strchr(curr->end->str, '\n')))
			return (push_line(&file, curr, line, temp));
		new_elem(curr);
	}
	free(file->end);
	file->end = NULL;
	return (push_line(&file, curr, line, NULL));
}
