/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 09:45:48 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/21 11:54:46 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**pipe_init(int len)
{
	int	i;
	int	**pipe_arr;

	pipe_arr = malloc(sizeof(int *) * (len + 1));
	if (!pipe_arr)
	{
		put_errmsg();
		return (0);
	}
	pipe_arr[0] = 0;
	i = 1;
	while (i < len)
	{
		pipe_arr[i] = malloc(sizeof(int) * 2);
		if (!pipe_arr[i])
			return (pipe_init_alloc_err(pipe_arr, i));
		if (pipe(pipe_arr[i]) < 0)
			return (pipe_init_err(pipe_arr, i));
		i++;
	}
	pipe_arr[len] = 0;
	return (pipe_arr);
}

void	is_path_pipe(char *str, char **argv)
{
	if (is_direc(str))
	{
		errno_print(EISDIR, str);
		exit (126);
	}
	execve(str, argv, format_envp());
	exit_path(str);
}

int	exec_util_pipe(t_cmd *cmd, char **path)
{
	char	*full_path;

	if (!path)
		return (NOCMD);
	while (*path)
	{
		full_path = get_full_path(cmd->argv[0], *path);
		if (!full_path)
		{
			put_errmsg();
			exit(FAIL);
		}
		if (file_exist(full_path))
		{
			execve(full_path, cmd->argv, format_envp());
			errno_print(errno, cmd->argv[0]);
			exit(FAIL);
		}
		free(full_path);
		path++;
	}
	return (NOCMD);
}

int	exec_pipe(t_list *cmd_list, char **path)
{
	pid_t	pid;
	int		**pipe_arr;
	int		i;

	pipe_arr = pipe_init(ft_lstsize(cmd_list));
	if (!pipe_arr)
		return (1);
	i = 0;
	while (cmd_list)
	{
		pid = fork();
		if (pid == -1)
			return (execve_err_pipe());
		if (pid == 0)
			child_do_pipe(cmd_list->content, path, pipe_arr, i);
		cmd_list = cmd_list->next;
		i++;
	}
	if (pid > 0)
		return (parents_do_pipe(pid, pipe_arr));
	return (1);
}
