/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:40:32 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/20 22:34:57 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_line(char **remainder, int fd, char **line, char *nl)
{
	char		*for_free;

	*nl = '\0';
	if (!(*line = ft_strdup(remainder[fd])))
	{
		free(remainder[fd]);
		return (-1);
	}
	for_free = remainder[fd];
	if (!(remainder[fd] = ft_strdup(nl + 1)))
	{
		free(for_free);
		return (-1);
	}
	free(for_free);
	return (1);
}

int			init(char **remainder, int fd)
{
	if (!remainder[fd])
	{
		if (!(remainder[fd] = ft_strdup("")))
			return (0);
	}
	return (1);
}

int			eof(char **remainder, int fd, char **line, ssize_t read_size)
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

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*for_free;
	char		*nl;
	static char	*remainder[OPEN_MAX];
	ssize_t		read_size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX
			|| !(init(remainder, fd)))
		return (-1);
	if ((nl = ft_strchr(remainder[fd], '\n')))
		return (get_line(remainder, fd, line, nl));
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		for_free = remainder[fd];
		if (!(remainder[fd] = ft_strjoin(remainder[fd], buf)))
		{
			free(for_free);
			return (-1);
		}
		free(for_free);
		if ((nl = ft_strchr(remainder[fd], '\n')))
			return (get_line(remainder, fd, line, nl));
	}
	return (eof(remainder, fd, line, read_size));
}
