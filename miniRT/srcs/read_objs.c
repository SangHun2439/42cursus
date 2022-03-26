/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:37:43 by sangjeon          #+#    #+#             */
/*   Updated: 2022/03/26 13:09:41 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_objs.h"
#include "libft.h"

void	read_objs(char *file_name)
{
	int		fd;
	char*	str;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(0);
	while (get_next_line(fd, &str))
	{
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
	close(fd);
}
