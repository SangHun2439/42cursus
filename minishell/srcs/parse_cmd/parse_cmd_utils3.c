/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:37:58 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:36 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_event_hook(void)
{
	return (0);
}

void	rlw_tmpf(int fd, char *arg)
{
	char					*line;
	int						len;
	extern rl_hook_func_t	*rl_event_hook;

	line = 0;
	len = ft_strlen(arg);
	signal(SIGINT, heredoc_sigint_handler);
	rl_event_hook = heredoc_event_hook;
	g_vars.heredoc_exit = 0;
	line = readline(">");
	while (line && ft_strncmp(line, arg, len) && !g_vars.heredoc_exit)
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline(">");
	}
	if (line)
		free(line);
	signal(SIGINT, sig_handler);
}

char	*get_tmpf_name(int num)
{
	char	*num_str;
	char	*res;

	num_str = ft_itoa(num);
	if (!num_str)
		return (0);
	res = ft_strjoin("my_tmp_", num_str);
	if (!res)
	{
		free(num_str);
		return (0);
	}
	free(num_str);
	return (res);
}

int	write_tmp_file(t_redi *redi)
{
	static int	id;
	char		*fname;
	int			fd;

	fname = get_tmpf_name(id);
	if (!fname)
		return (heredoc_err_mem(redi->arg));
	fd = open(fname, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0600);
	if (fd < 0)
		return (heredoc_err_fd(fname, redi->arg));
	rlw_tmpf(fd, redi->arg);
	close(fd);
	free(redi->arg);
	if (g_vars.heredoc_exit != 0)
		return (heredoc_err_sigint(fname));
	redi->arg = fname;
	id++;
	if (id == 32769)
		id = 0;
	return (0);
}

void	del_redi_one(void *content)
{
	t_redi	*redi;

	redi = content;
	if (!content)
		return ;
	if (redi->redi_status == REDIRECT_HEREDOC && file_exist(redi->arg))
		unlink(redi->arg);
	free(redi->arg);
	free(redi);
}
