/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_errhandle3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:39:16 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:33 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_err_mem(char *arg)
{
	free(arg);
	put_errmsg();
	return (1);
}

int	heredoc_err_fd(char *fname, char *arg)
{
	free(fname);
	free(arg);
	put_errmsg();
	return (1);
}

int	heredoc_err_sigint(char *fname)
{
	unlink(fname);
	free(fname);
	errno = 0;
	return (1);
}
