/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:30:38 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 13:44:24 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_cmd *cmd)
{
	char	*cmd_name;

	cmd_name = cmd->argv[0];
	if (!ft_strcmp(cmd_name, "echo"))
		return (ft_echo(cmd));
	else if (!ft_strcmp(cmd_name, "cd"))
		return (ft_cd(cmd));
	else if (!ft_strcmp(cmd_name, "pwd"))
		return (ft_pwd());
	else if (!ft_strcmp(cmd_name, "export"))
		return (ft_export(cmd));
	else if (!ft_strcmp(cmd_name, "unset"))
		return (ft_unset(cmd));
	else if (!ft_strcmp(cmd_name, "env"))
		return (ft_env(cmd));
	else if (!ft_strcmp(cmd_name, "exit"))
		return (ft_exit(cmd));
	return (NOCMD);
}

int	exec_util(t_cmd *cmd, char **path)
{
	char	*full_path;
	pid_t	pid;

	if (!path)
		return (NOCMD);
	while (*path)
	{
		full_path = get_full_path(cmd->argv[0], *path);
		if (!full_path)
			return (1);
		if (file_exist(full_path))
		{
			pid = fork();
			if (pid == -1)
				return (fork_err(full_path));
			if (pid == 0)
				return (child_do(full_path, cmd->argv, format_envp()));
			if (pid > 0)
				return (parents_do(pid, full_path));
		}
		free(full_path);
		path++;
	}
	return (NOCMD);
}

int	exec_ft_with_redi(t_cmd *cmd, char **path)
{
	int	res;
	int	fd_stdout;
	int	fd_stdin;

	save_fd_std(&fd_stdout, &fd_stdin);
	res = redirect(cmd->redi_list);
	if (res != 0)
		return (end_exec_ft(res, fd_stdout, fd_stdin));
	if (!cmd->argv[0])
		return (end_exec_ft(0, fd_stdout, fd_stdin));
	res = exec_builtin(cmd);
	if (res != NOCMD)
		return (end_exec_ft(res, fd_stdout, fd_stdin));
	if (ft_strchr(cmd->argv[0], '/') != NULL)
	{
		res = is_path(cmd->argv[0], cmd->argv);
		if (res != NODO)
			return (end_exec_ft(res, fd_stdout, fd_stdin));
	}
	res = exec_util(cmd, path);
	if (res != NOCMD)
		return (end_exec_ft(res, fd_stdout, fd_stdin));
	ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	return (end_exec_ft(res, fd_stdout, fd_stdin));
}

int	exec_ft(t_cmd *cmd, char **path)
{
	int	res;

	if (cmd->redi_list)
		return (exec_ft_with_redi(cmd, path));
	if (!cmd->argv[0])
		return (0);
	res = exec_builtin(cmd);
	if (res != NOCMD)
		return (res);
	if (ft_strchr(cmd->argv[0], '/') != NULL)
	{
		res = is_path(cmd->argv[0], cmd->argv);
		if (res != NODO)
			return (res);
	}
	res = exec_util(cmd, path);
	if (res != NOCMD)
		return (res);
	ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	return (res);
}

int	exec_cmd(t_list *cmd_list)
{
	int		res;
	char	**path;
	char	*path_str;

	if (!cmd_list)
		return (0);
	path_str = find_val("PATH");
	if (!path_str)
		path = 0;
	else
		path = ft_split(path_str, ':');
	if (!cmd_list->next)
		res = exec_ft(cmd_list->content, path);
	else
		res = exec_pipe(cmd_list, path);
	if (path)
		free_split(path);
	return (res);
}
