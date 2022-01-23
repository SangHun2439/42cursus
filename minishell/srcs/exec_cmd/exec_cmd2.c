/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:39:58 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 18:23:16 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	errno_print(int error, char *str)
{
	if (!error)
		return ;
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(error), STDERR_FILENO);
	errno = 0;
}

void	exit_path(char *str)
{
	int	res;

	res = 1;
	if (errno == ENOENT)
		res = 127;
	if (errno == EACCES)
		res = 126;
	errno_print(errno, str);
	exit(res);
}

int	is_path(char *str, char **argv)
{
	pid_t	pid;

	if (is_direc(str))
	{
		errno_print(EISDIR, str);
		return (126);
	}
	pid = fork();
	if (pid == -1)
		return (execve_err());
	if (pid == 0)
	{
		execve(str, argv, format_envp());
		exit_path(str);
	}
	if (pid > 0)
		return (parents_do(pid, NULL));
	return (NODO);
}

int	parents_do(pid_t pid, char *full_path)
{
	int		status;
	int		res;

	if (full_path)
		free(full_path);
	res = 0;
	status = 0;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		res = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		res = 128 + WTERMSIG(status);
		if (res == SIGINT + 128)
			printf("\n");
		else if (res == SIGQUIT + 128)
			printf("Quit: 3\n");
		else
			printf("Terminated by signal %d\n", res - 128);
	}
	return (res);
}

int	child_do(char *full_path, char **argv, char **envp)
{
	execve(full_path, argv, envp);
	exit_path(full_path);
	return (0);
}
