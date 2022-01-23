/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_errhandle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:25:51 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:31 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_err(void)
{
	put_errmsg();
	return (FAIL);
}

int	parse_err_cmd(char **cmd_arr, int res)
{
	free_split(cmd_arr);
	return (res);
}

int	parse_err_mem2(char **cmd_arr, t_cmd *cmd)
{
	put_errmsg();
	free_split(cmd_arr);
	free_split(cmd->argv);
	ft_lstclear(&(cmd->redi_list), del_redi_one);
	return (FAIL);
}

int	parse_err_mem3(t_list **cmd_line_list, t_list **redi_list)
{
	put_errmsg();
	list_clear(cmd_line_list, redi_list);
	return (FAIL);
}

int	parse_unexpected_err(void)
{
	errno = EUNEXPECTED;
	put_errmsg();
	return (FAIL);
}
