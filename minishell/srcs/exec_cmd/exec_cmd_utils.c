/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:40:32 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:27 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_exist(char *path)
{
	struct stat	buf;

	if (!stat(path, &buf))
		return (1);
	else
		return (0);
}

int	is_direc(char *path)
{
	struct stat	buf;

	stat(path, &buf);
	if (S_ISDIR(buf.st_mode))
		return (1);
	return (0);
}

char	*get_full_path(char *each_cmd, char *each_path)
{
	char	*full_path;
	int		i;

	if (!each_cmd || !each_path)
		return (0);
	i = ft_strlen(each_cmd) + ft_strlen(each_path);
	full_path = malloc(sizeof(char) * (i + 2));
	if (!full_path)
		return (0);
	i = 0;
	while (*each_path)
		full_path[i++] = *each_path++;
	full_path[i] = '/';
	i++;
	while (*each_cmd)
		full_path[i++] = *each_cmd++;
	full_path[i] = 0;
	return (full_path);
}

void	save_fd_std(int *fd_stdout, int *fd_stdin)
{
	*fd_stdout = dup(STDOUT_FILENO);
	*fd_stdin = dup(STDIN_FILENO);
}

void	getback_fd_std(int fd_stdout, int fd_stdin)
{
	dup2(fd_stdout, STDOUT_FILENO);
	dup2(fd_stdin, STDIN_FILENO);
	close(fd_stdout);
	close(fd_stdin);
}
