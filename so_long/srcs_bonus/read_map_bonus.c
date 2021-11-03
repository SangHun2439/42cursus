/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:54:05 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/03 11:50:42 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*read_file(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*res;
	char	*for_free;
	ssize_t	read_size;

	res = ft_strdup("\0");
	read_size = read(fd, buf, BUFFER_SIZE);
	buf[read_size] = 0;
	while (read_size > 0)
	{
		for_free = res;
		res = ft_strjoin(res, buf);
		free(for_free);
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = 0;
	}
	if (read_size < 0)
	{
		free(res);
		return (0);
	}
	for_free = res;
	res = ft_strjoin(res, buf);
	free(for_free);
	return (res);
}

void	each_check(int x, int y, char *p_check, t_map *map_info)
{
	if ((x == 0 || x == map_info->width - 1 || \
		y == 0 || y == map_info->height - 1) && \
		(map_info->map[y][x] != '1'))
		*p_check &= ~CLOSED;
	if (map_info->map[y][x] == 'C')
		*p_check |= COLLECT;
	if (map_info->map[y][x] == 'E')
		*p_check |= EXIT;
	if (map_info->map[y][x] == 'P')
	{
		*p_check |= PLAYER;
		map_info->p_x = x;
		map_info->p_y = y;
	}
}

int	map_check(t_map *map_info)
{
	char	check;
	int		x;
	int		y;

	check = 0 | (RECTANG + CLOSED);
	y = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			each_check(x, y, &check, map_info);
			x++;
		}
		if (x != map_info->width)
			check &= ~RECTANG;
		y++;
	}
	if (check != 31)
		return (0);
	return (1);
}

void	get_w_h(t_map *map_info)
{
	int	h;

	h = 0;
	map_info->width = ft_strlen(map_info->map[0]);
	while (map_info->map[h])
		h++;
	map_info->height = h;
}

int	map_parse(char *path, t_map *map_info)
{
	int		fd;
	char	*contents;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return (0);
	contents = read_file(fd);
	if (!contents)
		return (0);
	map_info->map = ft_split(contents, '\n');
	if (!map_info->map)
	{
		free(contents);
		return (0);
	}
	get_w_h(map_info);
	free(contents);
	if (!map_check(map_info))
	{
		split_free(map_info->map);
		return (0);
	}
	return (1);
}
