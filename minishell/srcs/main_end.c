/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:02:12 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:57 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_cmd(void *content)
{
	t_cmd	*cmd;

	cmd = content;
	free_split(cmd->argv);
	ft_lstclear(&(cmd->redi_list), del_redi_one);
	free(cmd);
}

void	init_err(void)
{
	put_errmsg();
	exit(1);
}
