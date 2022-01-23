/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:04:30 by sangjeon          #+#    #+#             */
/*   Updated: 2022/01/20 12:06:53 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	case_cmd(char **one_cmd_ptr, t_list **cmd_line_list_ptr)
{
	char	*str;
	t_list	*new_lst;

	str = get_word_move_addr(one_cmd_ptr);
	if (!str)
		return (parse_err());
	new_lst = ft_lstnew(str);
	if (!new_lst)
	{
		free(str);
		return (parse_err());
	}
	ft_lstadd_back(cmd_line_list_ptr, new_lst);
	return (0);
}

int	case_redi(char **one_cmd_ptr, t_list **redi_list_ptr, int redi_status)
{
	t_redi	*redi;
	t_list	*new_lst;

	redi_move_ptr(one_cmd_ptr, redi_status);
	if (!**one_cmd_ptr || is_redi(*one_cmd_ptr))
		return (parse_unexpected_err());
	redi = malloc(sizeof(t_redi));
	if (!redi)
		return (parse_err());
	redi->redi_status = redi_status;
	redi->arg = get_word_move_addr(one_cmd_ptr);
	if (!redi->arg)
		return (parse_err_redi(redi));
	if (redi->redi_status == REDIRECT_HEREDOC)
	{
		if (write_tmp_file(redi) != 0)
			return (parse_err_redi(redi));
	}
	new_lst = ft_lstnew(redi);
	if (!new_lst)
		return (mem_err_redi2(redi));
	ft_lstadd_back(redi_list_ptr, new_lst);
	return (0);
}

int	fill_cmd_redi_list(char **one_cmd_ptr, \
t_list **cmd_line_list_ptr, t_list **redi_list_ptr)
{
	int		redi_status;
	int		res;

	redi_status = is_redi(*one_cmd_ptr);
	if (!redi_status)
		res = case_cmd(one_cmd_ptr, cmd_line_list_ptr);
	else
		res = case_redi(one_cmd_ptr, redi_list_ptr, redi_status);
	if (res != SUCCESS)
		list_clear(cmd_line_list_ptr, redi_list_ptr);
	return (res);
}

int	only_dollar(char **res)
{
	if (write_str(res, '$', 0) != SUCCESS)
		return (1);
	return (0);
}

int	get_recent_status(char **str_ptr, char **res)
{
	char	*recent_status;
	char	*for_free;

	(*str_ptr)++;
	recent_status = ft_itoa(g_vars.last_status);
	for_free = recent_status;
	if (!recent_status)
		return (FAIL);
	while (*recent_status)
	{
		if (write_str(res, *recent_status, 0) != SUCCESS)
		{
			free(for_free);
			return (1);
		}
		recent_status++;
	}
	free(for_free);
	return (SUCCESS);
}
