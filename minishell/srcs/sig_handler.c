/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:55:32 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:07:00 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_sigint_handler(int sig)
{
	extern int	rl_done;

	if (sig == SIGINT)
	{
		g_vars.heredoc_exit = 1;
		rl_done = 1;
		return ;
	}
}

void	sigint_handler(void)
{
	int	status;

	if (waitpid(-1, &status, WNOHANG) == -1 && errno == ECHILD)
	{
		g_vars.last_status = 1;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		errno = 0;
	}
}

void	sigquit_handler(void)
{
	return ;
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
		return (sigint_handler());
	if (sig == SIGQUIT)
		return (sigquit_handler());
}
