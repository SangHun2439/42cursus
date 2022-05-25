/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:40:32 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/25 10:20:21 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(char **remainder, int fd, char **line, char *nl)
{
	char		*for_free;

	*nl = '\0';
	*line = ft_strdup(remainder[fd]);
	if (!(*line))
	{
		free(remainder[fd]);
		return (-1);
	}
	for_free = remainder[fd];
	remainder[fd] = ft_strdup(nl + 1);
	if (!(remainder[fd]))
	{
		free(for_free);
		return (-1);
	}
	free(for_free);
	return (1);
}

int	init(char **remainder, int fd)
{
	if (!remainder[fd])
	{
		remainder[fd] = ft_strdup("");
		if (!(remainder[fd]))
			return (0);
	}
	return (1);
}

int	eof(char **remainder, int fd, char **line, ssize_t read_size)
{
	if (read_size < 0)
	{
		free(remainder[fd]);
		return (-1);
	}
	*line = remainder[fd];
	remainder[fd] = 0;
	return (0);
}

int	get_next_line2(int fd, char **line, char buf[], char *remainder[])
{
	ssize_t		read_size;
	char		*for_free;
	char		*nl;

	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		for_free = remainder[fd];
		remainder[fd] = ft_strjoin(remainder[fd], buf);
		if (!(remainder[fd]))
		{
			free(for_free);
			return (-1);
		}
		free(for_free);
		nl = ft_strchr(remainder[fd], '\n');
		if (nl)
			return (get_line(remainder, fd, line, nl));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (eof(remainder, fd, line, read_size));
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*nl;
	static char	*remainder[OPEN_MAX];

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX \
	|| !(init(remainder, fd)))
		return (-1);
	nl = ft_strchr(remainder[fd], '\n');
	if (nl)
		return (get_line(remainder, fd, line, nl));
	return (get_next_line2(fd, line, buf, remainder));
}
