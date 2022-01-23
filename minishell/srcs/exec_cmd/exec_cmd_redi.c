/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_redi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:56:46 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:26 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_append(char *arg)
{
	int		fd;

	fd = open(arg, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
		return (end_redirect_err());
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	redirect_heredoc(char *arg)
{
	int		fd;

	fd = open(arg, O_RDONLY);
	unlink(arg);
	if (fd < 0)
		return (end_redirect_err());
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	redirect_input(char *arg)
{
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (end_redirect_err());
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	redirect_output(char *arg)
{
	int		fd;

	fd = open(arg, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (end_redirect_err());
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	redirect(t_list *redi_list)
{
	t_redi	*redi;
	int		res;

	while (redi_list)
	{
		redi = redi_list->content;
		if (redi->redi_status == REDIRECT_APPEND)
			res = redirect_append(redi->arg);
		else if (redi->redi_status == REDIRECT_HEREDOC)
			res = redirect_heredoc(redi->arg);
		else if (redi->redi_status == REDIRECT_INPUT)
			res = redirect_input(redi->arg);
		else if (redi->redi_status == REDIRECT_OUTPUT)
			res = redirect_output(redi->arg);
		if (res != 0)
			return (res);
		redi_list = redi_list->next;
	}
	return (0);
}
