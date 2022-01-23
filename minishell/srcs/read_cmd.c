/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:10:57 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:59 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cmd.h"

void	eof_handler(void)
{
	ft_putstr_fd("exit minishell\n", STDOUT_FILENO);
	exit(0);
}

char	*rl_gets(void)
{
	static char	*line_read;
	extern int	rl_catch_signals;

	rl_catch_signals = 0;
	if (line_read)
	{
		free(line_read);
		line_read = 0;
	}
	line_read = readline("eakshell~$ ");
	if (!line_read)
		eof_handler();
	if (line_read && *line_read)
		add_history(line_read);
	return (line_read);
}
