/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:57:48 by jkrypto           #+#    #+#             */
/*   Updated: 2019/12/14 14:55:53 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	next_line(int fd, int cnt, char **str, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while (str[fd][len] && str[fd][len] != '\n')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		temp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = temp;
		if (!str[fd][0])
			ft_strdel(&str[fd]);
	}
	else if (!str[fd][len])
	{
		if (cnt == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			cnt;
	char		*temp;
	char		buff[BUFF_SIZE + 1];
	static char	*str[255];

	if (fd < 0 || !line)
		return (-1);
	while ((cnt = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[cnt] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		temp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (cnt < 0)
		return (-1);
	else if (!cnt && (!str[fd] || !str[fd][0]))
		return (0);
	return (next_line(fd, cnt, str, line));
}
