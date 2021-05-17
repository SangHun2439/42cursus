/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:40:32 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/17 13:20:21 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp_str;
	ssize_t		read_size;
	int			idx;
	static char	*remain_line;

	if(!(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	*line = '\0';
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (idx = ft_strchr(buf, '\n'))
		{
			buf[idx] = '\0';
			*line = ft_strjoin(tmp_str, buf);
			remain_line = ft_strdup(buf[idx + 1]);
		}
		tmp_str = ft_strdup(buf);
		
	}
}
