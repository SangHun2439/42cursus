/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_pipe2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:42:44 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/21 12:15:00 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_all_pipe(int **pipe_arr)
{
	int	i;

	i = 1;
	while (pipe_arr[i])
	{
		close(pipe_arr[i][RPIPE]);
		close(pipe_arr[i][WPIPE]);
		i++;
	}
}

void	connect_pipe(int *rpipe, int *wpipe)
{
	if (rpipe)
		dup2(rpipe[RPIPE], STDIN_FILENO);
	if (wpipe)
		dup2(wpipe[WPIPE], STDOUT_FILENO);
}

void	child_do_pipe(t_cmd *cmd, char **path, int **pipe_arr, int num)
{
	int	res;

	connect_pipe(pipe_arr[num], pipe_arr[num + 1]);
	close_all_pipe(pipe_arr);
	if (cmd->redi_list)
	{
		res = redirect(cmd->redi_list);
		if (res != 0)
			exit(res);
	}
	res = exec_builtin(cmd);
	if (res != NOCMD)
		exit(res);
	if (ft_strchr(cmd->argv[0], '/') != NULL)
		is_path_pipe(cmd->argv[0], cmd->argv);
	res = exec_util_pipe(cmd, path);
	if (res != NOCMD)
		exit(res);
	ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	exit(res);
}

void	free_pipe(int **pipe_arr)
{
	int	i;

	i = 1;
	while (pipe_arr[i])
	{
		free(pipe_arr[i]);
		i++;
	}
	free(pipe_arr);
}

int	parents_do_pipe(pid_t pid, int **pipe_arr)
{
	int	res;
	int	status;

	res = 0;
	status = 0;
	close_all_pipe(pipe_arr);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		res = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		res = 128 + WTERMSIG(status);
	while (wait(0) > 0)
		;
	free_pipe(pipe_arr);
	errno = 0;
	return (res);
}
